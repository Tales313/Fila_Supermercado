# Fila_Supermercado
Primeiro projeto da disciplina de Estrutura de Dados (Sistemas para Internet, IFPB) feito em 2017.2.

## Descrição
Os clientes devem ser programados em uma fila e chegam em intervalos de 1 a 5 minutos. Além disso, cada cliente é atendido em intervalos aleatórios de 1 a 5 minutos. Obviamente, as taxas de chegada e de atendimento precisam ser equilibradas. Se a taxa média de chegada for maior que a taxa média de atendimento, a fila crescerá indefinidamente. Mesmo com taxas equilibradas, o caráter aleatório da chegada e
do atendimento ainda pode causar filas imensas. 

Cada cliente deverá possuir as seguintes informações:
- o seu número de identificação (inteiro sequencial);
- o minuto no qual ele chega na fila (inteiro aleatório entre 1 e 5, adicionado ao minuto atual);
- o seu tempo de atendimento (inteiro aleatório entre 1 e 5).
Faça o programa de simulação de supermercado para simular um período de 12 horas (720 minutos).

Algoritmo sugerido:
1. Crie uma fila (vazia).
2. Determine os dados do primeiro cliente.
3. Para cada minuto do dia, faça:
3.1. Se chegar o cliente:
3.1.1. Coloque-o na fila.
3.1.2. Determine os dados do próximo cliente.
3.2. Se existir cliente em atendimento:
3.2.1. Atenda o cliente atual.
3.3. Se o caixa estiver livre:
3.3.1. Tire da fila o próximo cliente a ser atendido.
3.3.2. Coloque o cliente em atendimento.

Após a execução da simulação, o programa deve responder as seguintes perguntas:
1) Qual o número máximo de clientes na fila no período da simulação?
2) Qual a espera máxima experimentada por um dos clientes?
Observações:
a) O programa deve utilizar qualquer uma das bibliotecas do TAD Fila definidas nas aulas (sequencial ou encadeada).
b) Parametrize os tempos (da chegada do cliente, do atendimento e da simulação) de modo que se possa testar diferentes configurações.

## Screenshots

![Screenshot 1](/screenshots/1.png)
![Screenshot 2](/screenshots/2.png)
![Screenshot 3](/screenshots/3.png)
![Screenshot 4](/screenshots/4.png)
