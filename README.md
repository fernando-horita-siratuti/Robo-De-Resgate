# Robo-De-Resgate

## Sobre o Projeto

O **RoboDeResgate** é um sistema desenvolvido para auxiliar no resgate de astronautas em uma estação espacial. O robô navega por uma matriz representando o ambiente espacial, localizando astronautas e evitando áreas perigosas como fogo e obstáculos intransitáveis.

As principais funcionalidades incluem:
- Navegação na estação espacial utilizando algoritmo de busca em largura (BFS).
- Impressão do caminho percorrido pelo robô em tempo real.
- Geração de relatório detalhado dos astronautas resgatados e não resgatados, incluindo suas condições de saúde.

Para a implementar as matrizes é necessário implementá-las em um arquivo chamado "entrada1.txt", "entrada2.txt", etc. Além disso, tais matrizes precisam estar nesse formato:

Descrição: 
- Primeira linha: dimensões da matriz.
- Elementos da matriz
- Astronautas: nome, nível de saúde e atendimento urgente dos astronautas
- Posições dos astronautas da matriz: nome e coordenadas dos astronautas

10 10
S.........

.###..#..A

.###..#...

.~~~..F..A

.~~~..F.A.

A~~~..F.F.

.~~~..F...

.....F....

..A..F....

..........

Astronautas:
Yuri Gagarin,85,0
Neil Armstrong,60,1
Buzz Aldrin,95,0
Marcos Pontes,50,1
Valentina Tereshkova,70,0

Posições dos astronautas na matriz:
Yuri Gagarin: (1,9)
Neil Armstrong: (4,8)
Buzz Aldrin: (5,0)
Marcos Pontes: (8,2)
Valentina Tereshkova: (3,9)

---

## Funcionalidades

### Iniciar Resgate
- O robô inicia na posição configurada no construtor e utiliza BFS para encontrar o caminho mais curto até um astronauta.
- Ele evita áreas de fogo (`'F'`), obstáculos (`'#'`) e vácuo (`'~'`).
- O astronauta apenas é salvo caso ele não esteja a uma posição de distância de um fogo (verticalmente ou horizontalmente).
- O caminho percorrido é exibido no terminal, mostrando a posição atual do robô (`R`) e o trajeto percorrido (`*`).

### Imprimir Caminho
- Exibe o mapa da estação espacial no terminal, marcando:
  - `R`: Posição atual do robô.
  - `*`: Caminho percorrido pelo robô.
  - `A`: Astronautas da estação.
  - Outros caracteres representam o ambiente da estação (`F`, `#`, `~`, etc.).

### Relatório de Resgate
- Após concluir o resgate, um relatório é gerado contendo:
  - Lista de astronautas resgatados e não resgatados, incluindo:
    - Nome, nível de saúde, necessidade de atendimento urgente e posição na matriz.
  - Tempo total da operação (em passos) dados pelo robô.
