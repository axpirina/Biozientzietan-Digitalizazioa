---
layout: home
title: Hasiera
---

<style>
@media (min-width: 1024px) {
  body {
    background: linear-gradient(135deg, #1e3c72 0%, #2a5298 100%);
    padding: 30px 50px;
  }
  .page-wrapper {
    max-width: 1600px;
    margin: 0 auto;
  }
  .main-content {
    background: white;
    border-radius: 15px;
    padding: 50px;
    box-shadow: 0 10px 40px rgba(0,0,0,0.2);
  }
  h1 {
    font-size: 3em;
  }
  h2 {
    font-size: 2em;
  }
  p, li {
    font-size: 1.1em;
  }
  table {
    font-size: 1em;
  }
}
@media (max-width: 768px) {
  .main-content {
    padding: 20px;
  }
}
</style>

# Biozientzietan Digitalizazioa

ESP8266 NodeMCU eta DHT11 sensoreak erabiliz, tenperatura, hezetasuna eta egonaldi bero indizea ThingsBoard-era bidaltzeko plataforma.

## Ezaugarriak

- **Tenperatura**: DHT11 sentsorea (0-50°C, ±2°C)
- **Hezetasuna**: DHT11 sentsorea (20-90% RH, ±5%)
- **Egonaldi Bero Indizea**: Kalkulatutako intzipazio-puntua
- **Hiri koordenatuak**: 17 herrietako latitude eta longitude
- **Denbora errealeko dashboard**: ThingsBoard

## Atalak

| Atala | Deskribapena |
|-------|-------------|
| [Irudiak](./Irudiak/) | Zirkuituaren irudiak |
| [Datu orriak](./datu%20orriak/) | Datu fitxak |
| [Eskuliburuak](./Eskuliburuak/) | Dokumentazioa |