# TrabalhoFinalESTDADOS

# Sobre o projeto
Projeto final da Disciplina de Estrutura de Dados I do Curso de Bacharelado em Ciência da Computação do Instituto Federal Catarinense - Campus Videira, ministrada pelo Professor Dr. Manassés Ribeiro, cujo intuito era a implementaçãode uma tabela de espalhamento(tabela hashing) em um arquivo .txt contendo mais de 100 mil nomes.

## Objetivo do Trabalho
Implementar a tabela hash em um arquivo .txt contendo mais de 100 mil nomes a fim de organizá-los adequadamente utilizando fila encadeada dupla, e o quicksort para organizar de forma alfabética as chaves. 

# Como funciona o projeto
O projeto se constitui começa pela escolha das biblitecas necessárias, a definição de uma constante de valor 53, referente aos números de chaves, e a criação de structs de lista e de nodo:

![image](https://github.com/OtavioOLDG/TrabalhoFinalESTDADOS/assets/131627256/6c956267-a622-46a2-97e9-0a9bdda65ffa)

Após são feitas as declarações das funções e dos métodos utilizados. 

![image](https://github.com/OtavioOLDG/TrabalhoFinalESTDADOS/assets/131627256/63537efb-d7fd-4b50-9a08-7c98ba2e0774)

Os métodos de criação de Nodo, Hash Table e List são usados para a alocação de memória, ou seja, são aqueles padrões utilizados na linguagem C;

Tem também as funões para conferir se a lista está vazia e também o tratamento de erros do código.

![image](https://github.com/OtavioOLDG/TrabalhoFinalESTDADOS/assets/131627256/3ef8c2e7-7e6b-4872-a574-777fac93b605)

O método de inserção coloca o nome informado na "head" e assim segue a lista, sendo passado como parâmetro a lista hash e o nome.

![image](https://github.com/OtavioOLDG/TrabalhoFinalESTDADOS/assets/131627256/25587fbf-829b-49b5-94ed-ef583c149a87)

O método de remoção busca o nome informado dentro dos hashings e fazendo sua remoção, caso o nome seja nulo(NULL) será removido o primeiro da fila de saída (tail).

![image](https://github.com/OtavioOLDG/TrabalhoFinalESTDADOS/assets/131627256/9d21e921-33c1-4830-b1a9-55c9d0dcc2af)

A função nodoName procura um nome dentre os hashings que, caso não encontrado retorna nulo.

![image](https://github.com/OtavioOLDG/TrabalhoFinalESTDADOS/assets/131627256/c9f601d2-5216-4762-a4ba-72edc95e3e22)

A função hashingFunction retorna um valor utilizado para a separação entre os hashings.

![image](https://github.com/OtavioOLDG/TrabalhoFinalESTDADOS/assets/131627256/861e6c0a-b6d5-4e01-aeb3-e181a9ed7428)

Os três seguintes métodos são utilizados para mero funcionamento do código sendo elas de dizer se há um nome nas listas, tornar maiúscula a primeira letra e minúsculas as palavras.

![image](https://github.com/OtavioOLDG/TrabalhoFinalESTDADOS/assets/131627256/ca1a7e13-4676-49b0-aa74-0e902a69dc20)

O compare compara os nodos para ser utilizado no método seguinte de quicksort.

![image](https://github.com/OtavioOLDG/TrabalhoFinalESTDADOS/assets/131627256/b202dc8e-8f4a-49ec-9b09-637a41af5b7f)

## Função de hashing
Eu pessoalmente andei buscando pela internet e encontrei vídeos onde era mostrado a função de hashing, porém encontrei um que gostei e implementei no presente código, de forma que a palavra é lida letra por letra, sendo o valor da letra multiplicado pela sua respectiva ordem, ou seja se a letra 'a' for a segunda letra, então será multiplicado o valor de a por 2, e assim somando sucessivamente até o final dela, gerando um valor que realizará um operação de divisão de inteiros com o número constante das chaves (53):

![image](https://github.com/OtavioOLDG/TrabalhoFinalESTDADOS/assets/131627256/861e6c0a-b6d5-4e01-aeb3-e181a9ed7428)

O seguinte gráfico mostra como foi divididos os nomes com êxito, visto que os hashings ficaram em uma faixa muito similar em número de nomes:

![image](https://github.com/OtavioOLDG/TrabalhoFinalESTDADOS/assets/131627256/1b3a2111-47ce-493e-9167-682cf95cd183)

![image](https://github.com/OtavioOLDG/TrabalhoFinalESTDADOS/assets/131627256/26476ae1-3912-4f4f-bf74-b391e3a7ede9)










# Autor

Otávio Lunardelli de Giacometti

www.linkedin.com/in/otavio-lunardelli-de-giacometti-230421271
