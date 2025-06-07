# ⚡ Projeto Zeus – Monitoramento Inteligente com Arduino e MediaPipe

## 🧾 Visão Geral

Este projeto integra **soluções com Arduino** e **visão computacional com MediaPipe** para fornecer dados em tempo real sobre **quedas de energia** e **riscos ambientais** próximos a redes elétricas. As informações são centralizadas na **plataforma Zeus**, que fornece Informações climáticas, probabilidade de queda de energia e alertas de notícias.

---

## 🛠️ Soluções Implementadas

### 🔌 Arduino – Monitoramento de Quedas de Energia

- **Função:** Detectar automaticamente quedas de energia elétrica em pontos monitorados.
- **Como funciona:**
  - Sensor de luz identifica a presença ou ausência de energia.
  - Dados como valor do sensor, horário e local são enviados via `Serial`.
  - As informações são **salvas na EEPROM** em caso de falha ou reinício, garantindo persistência.

- **Impacto:**
  - Garante confiabilidade mesmo com instabilidade elétrica.
  - Permite registro histórico de quedas para auditoria e prevenção.

---

### 🌳 MediaPipe – Detecção de Riscos Ambientais

- **Função:** Utiliza câmera e MediaPipe para identificar movimentos bruscos de **objetos ou vegetações** (como galhos e árvores) próximos a redes elétricas.
- **Como funciona:**
  - Processa imagens para identificar formas e padrões relacionados a objetos em áreas de risco.
  - Alertar quando árvores ou barreiras físicas estiverem invadindo zonas críticas ou realizando movimentos bruscos.

- **Impacto:**
  - Ajuda na prevenção de acidentes causados por quedas de árvores ou interferências em redes.
  - Automatiza inspeções visuais de áreas perigosas, reduzindo custo e tempo de resposta.

---

## 🚀 Benefícios para a Plataforma Zeus

- **📊 Dados Confiáveis e em Tempo Real:** Informações integradas chegam à plataforma para análise imediata.
- **🔒 Resiliência Operacional:** Dados locais armazenados mesmo sem conexão ou energia.
- **🌐 Monitoramento Híbrido:** Une sensores físicos com análise visual automatizada.
- **⚠️ Prevenção Ativa:** Alertas sobre obstáculos ou riscos antes que causem danos reais.
- **🏘️ Aplicabilidade Ampla:** Ideal para uso urbano e rural, especialmente em áreas com vegetação densa ou redes expostas.

---

## ✅ Conclusão

Combinando sensores do **Arduino** com a análise visual do **MediaPipe**, a **Plataforma Zeus** torna-se uma ferramenta poderosa para a **gestão preventiva de energia e segurança de infraestrutura elétrica**, promovendo **eficiência, segurança e inteligência ambiental**.

## 👥 Integrantes

- 🎓 Lucas Rodrigues Delfino - `RM550196`
- 🎓 Luisa Cristina dos Santos Neves - `RM551889`
- 🎓 Gabriel Aparecido Cassalho Xavier - `RM99794`
