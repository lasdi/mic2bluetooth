<h1 align="center">
    <img alt="Banner" title="#Banner" src="./dir-assets/banner.jpeg" />
</h1>

# Projeto de Microfone I2S em Tempo Real para Bluetooth


<strong>Português 🇧🇷</strong>
<br>
[English 🇺🇸](./README-en.md) 

## Visão Geral

Este projeto é uma aplicação de streaming de áudio em tempo real que lê dados de um microfone I2S e os envia para um dispositivo Bluetooth usando o Framework de Desenvolvimento de IoT Espressif (ESP-IDF) na versão 5.1.1.

![Imagem do Projeto](inserir_url_da_imagem_aqui)

## Contexto

Este projeto foi desenvolvido como parte de um curso de Sistema de Tempo Real no bacharelado de Engenharia de Computação da Universidade Federal do Recôncavo da Bahia.

## Configuração do Bluetooth

Antes de começar, certifique-se de ter instalado as ferramentas ESP-IDF, configurado o dispositivo alvo e ajustado o seu projeto, modificando o arquivo `preferences.h` de acordo com o seu hardware e preferências específicas.

### Configuração do Bluetooth

- `TARGET_DEVICE_NAME`: Defina o nome do dispositivo Bluetooth de destino.
- `LOCAL_DEVICE_NAME`: Defina o nome do seu dispositivo ESP, conforme aparecerá para outros dispositivos.

### Configuração do I2S

- `WS_IO_PORT`: Configure o pino GPIO para o sinal Word Select (WS) do microfone I2S.
- `SD_PORT`: Configure o pino GPIO para o sinal de Dados Seriais (SD).
- `SCK_PORT`: Configure o pino GPIO para o sinal do Clock Serial (SCK).
- `I2S_NUM`: Defina o número da porta I2S (geralmente I2S_NUM_0 para a maioria das placas ESP32).

### Configuração de Áudio I2S

- `FRAME_RATE`: Defina a taxa de quadros para os dados de áudio.
- `N_WINDOW_ELEMENTS`: Defina o número de elementos de janela para o processamento de áudio.

### Configuração da Fila

- `MAX_SIZE_QUEUE`: Configure o tamanho máximo da fila para o buffer de dados de áudio.

## Compilação e Gravação

Para compilar e gravar o projeto no seu dispositivo ESP32, siga o processo padrão de compilação ESP-IDF. Certifique-se de ter definido o caminho do IDF e o dispositivo alvo usando os comandos `idf.py set-target` e `idf.py set-idf-path`. Você pode consultar a [documentação do ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/v5.1.1/get-started/index.html) para obter instruções detalhadas.

## Uso

Depois que o projeto for gravado no seu dispositivo ESP32, ele lerá dados de áudio do microfone I2S e os transmitirá para o dispositivo Bluetooth especificado com os nomes configurados.

## Contato

Se você tiver alguma dúvida ou gostaria de contribuir para este projeto, entre em contato com os colaboradores.

- Andersoney Rodrigues
  - Email: andresoney@gmail.com
  - GitHub: github.com/andersoney

- Filipe Correia
  - Email: f7lipe@aluno.ufrb.edu.br
  - GitHub: github.com/f7lipe

- Igor Miranda
  - Email: igordantas@ufrb.edu.br
  - GitHub: github.com/igordsm83

- Paulo Cesar
  - Email: paulo.rocha@aluno.ufrb.edu.br
  - GitHub: github.com/paul0Cesar
