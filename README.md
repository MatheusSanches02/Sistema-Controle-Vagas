# Sistema-Controle-Vagas
Esse repositório serve para armazenar códigos de um controlador de vagas feito em arduino. 

Circuito feito com o tinkercad, link do circuito: https://www.tinkercad.com/things/2Ap432XAH2s?sharecode=Quq9S_545v7L8eONhnpe2-nzVTrh0cMliuHt5o8uPBI

Componentes Utilizados:

• 2 (dois) sensores ultrassônicos;
• 2 (dois) LEDs vermelhos;
• 2 (dois) LEDs verdes
• 1 (um) display LCD.


Problema a ser resolvido:

Um dos grandes problemas do trânsito é encontrar uma vaga para estacionar. Buscando auxiliar os clientes de um estacionamento, a empresa precisa desenvolver uma aplicação que faça a detecção de quantas vagas estão disponíveis.

Como o sistema vai funcionar:

Suponha que cada sensor ultrassônico está instalado na altura de 2 m do solo, posicionado acima de uma vaga para estacionar. Sendo assim, se um carro parar nesta vaga, o sensor detectará uma distância menor que 2 m, indicando que o local foi preenchido.

Cada vaga deverá ter um sensor ultrassônico, um LED vermelho e um LED verde. Se a vaga estiver ocupada, o LED vermelho deverá acender e o verde apagar, caso contrário, o LED verde deverá ficar ligado e o vermelho desligado.

O display LCD deverá mostrar a quantidade de vagas LIVRES e a quantidade de vagas OCUPADAS do estacionamento.


--------

Segunda parte do projeto, ocorre com as simulção do envio de quais vagas estão disponíveis, inspirado em uma arquitetura de IoT simples, um gateway utilizando o node-red.

Como o sistema vai funcionar:

Um flow recebe as informações dos sensores e envia para o segundo flow que irá exibir em um dashboard o status das vagas.

Fluxo_Publisher - Gateway que recebe as informações das vagas via serial e envia (publisher) via protocolo MQTT. Simule o estacionamento com 2 vagas (vaga A e vaga B) utilize o node “inject”. O formato da mensagem dos sensores é:

• Somente a vaga A disponível → envia “A”
• Somente a vaga B disponível → envia “B”
• Ambas as vagas disponíveis → envia “AB”
• Nenhuma vaga disponível → envia “X”

Fluxo-Subscriber - Dashboard que recebe (subscriber) os dados via protocolo MQTT e exibe o status em um Dashboard.
