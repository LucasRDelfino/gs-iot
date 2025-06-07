import cv2
import numpy as np
from datetime import datetime

# Abrir vídeo ou webcam
cap = cv2.VideoCapture('video_arvore.mp4')

cv2.namedWindow('Monitoramento', cv2.WINDOW_NORMAL)
cv2.resizeWindow('Monitoramento', 640, 480)

if not cap.isOpened():
    print("❌ Erro: Não foi possível abrir o vídeo ou a webcam.")
    exit()

# Inicializar o primeiro frame
ret, frame1 = cap.read()
ret, frame2 = cap.read()

while cap.isOpened():
    diff = cv2.absdiff(frame1, frame2)
    gray = cv2.cvtColor(diff, cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(gray, (5,5), 0)
    _, thresh = cv2.threshold(blur, 20, 255, cv2.THRESH_BINARY)
    dilated = cv2.dilate(thresh, None, iterations=3)
    contours, _ = cv2.findContours(dilated, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    movimento_detectado = False

    for contour in contours:
        if cv2.contourArea(contour) < 80000:
            continue
        x, y, w, h = cv2.boundingRect(contour)
        if w < 50 or h < 50:
            continue
        movimento_detectado = True
        cv2.rectangle(frame1, (x,y), (x+w, y+h), (0,255,0), 2)
        cv2.putText(frame1, 'Movimento Detectado!', (x, y-10),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.9, (0,0,255), 2)

    if movimento_detectado:
        agora = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        local = "Santo Amaro - A1"

        # 🗄️ Simular exportação para base SQL
        sql = f"INSERT INTO monitor_energia (evento, local, horario) VALUES ('Queda detectada', '{local}', '{agora}');"
        print("⚠️ ALERTA: Movimento anormal detectado! Risco de queda!")
        print("🗄️ Exportando dados para banco:")
        print(sql)

    cv2.imshow('Monitoramento', frame1)

    frame1 = frame2
    ret, frame2 = cap.read()

    if not ret:
        print("✔️ Fim do vídeo ou erro na captura.")
        break

    if cv2.waitKey(40) & 0xFF == ord('q'):
        print("✔️ Execução encerrada pelo usuário.")
        break

cap.release()
cv2.destroyAllWindows()
