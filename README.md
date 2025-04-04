# TickTracket - Gerenciador de Tickets
Programação II - 2024/2 - UFES

## Objetivo
O objetivo deste trabalho é colocar em prática as habilidades de programação na linguagem C adquiridas ao longo do curso. O trabalho foi elaborado para exercitar diversos conceitos, principalmente a construção de TADs opacos e genéricos, alocação e manipulação de memória de maneira dinâmica.

## Descrição geral do sistema
A intenção principal do TickTrack é gerenciar digitalmente os tickets solicitados em uma organização fictícia. Para isso, deve ser considerado as seguintes premissas:
- O sistema possui três atores principais: usuário, técnico e empresas fornecedoras
- O sistema deve ser capaz de cadastrar ambos os atores
- O usuário abre tickets para solicitar algum serviço
- O técnico recebe os tickets para solucionar o problema solicitado de acordo com a disponibilidade de tempo dos mesmos
- Existem 4 tipos de tickets disponíveis no sitema: SOFTWARE, MANUTENÇÃO, OUTROS e HARDWARE
- Cada ticket tem uma série de particularidades e para cada um deles é estabelecido um tempo de solução
- Os tickets devem ser distribuídos entre os técnicos respeitando uma fila
- O sistema deve ser capaz de notificar todos os tickets do sistemas
- O sistema deve ser capaz de realizar relatórios em relação aos atores e tickets

Dessa forma, o TickTrack deve ser capaz de fornecer as seguintes funcionalidades:
1. Cadastro de Usuários, Técnicos e Empresas Fornecedoras
2. Abertura de Ticket com inserção em uma fila
3. Distribuição dos tickets para os técnicos
4. Notificação de tickets
5. Relatórios solicitados

Todas as interações com o programa são realizadas utilizando entrada e saída padrão. Em outras palavras, lendo e escrevendo na tela do terminal (verifique a pasta casos neste repositório).

## Como compilar e rodar

### Estrutura
O repositório é organizado da seguinte forma:
- Uma pasta chamda Codigo, onde estão presentes dos os .c e .h do programa
- Uma pasta chamada Casos, onde estão todas entradas e saídas esperadas para o programa

### Compilação
Entre na pasta Codigo e execute:

```markdown
gcc *.c -o main
```

Assim, com o executável main gerado, execute-o com as determinadas entradas da pasta Casos.

## Autor
- Arthur Prado [crarthur2](https://github.com/crarthur2)







