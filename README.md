# Solucionador de Expressões
## Descrição do programa
>O intuito do programa é ser capaz de resolver e converter expressões infixas e posfixas, sendo essa
>também chamada de notação polonesa inversa.
>Uma expressão infixa é aquela ao qual estamos habituados a resolver, usando parênteses e
>colocando o operador entre os operandos, por exemplo : `(3 + 4) + ( 5 * 2 )`. Já na notação 
>polonesa inversa, a ordem dos elementos é essencial para a interpretação correta da expressão. 
>Ela elimina a necessidade de usar parênteses para indicar a ordem de avaliação das operações. 
>Em vez disso, usa-se a ordem em que os elementos são apresentados, exemplo : `3 4 + 5 *`.

## Instruções de compilação
>Para compilar o programa digite no terminal do Linux:
```bash
make
```
## Comandos
1. `LER POSFIXA` <EXPRESSÃO VEM AQUI>
2. `LER INFIXA` <EXPRESSÃO VEM AQUI>
3. `INFIXA`, esse comando converte uma expressão pos-fixada armazenada anteriormente.
4. `POSFIXA`, esse comando converte uma expressão infixa armazenada anteriormente.
5. `RESOLVE`, esse comendo resolve a expressão armazenada, independentemente se for infixa ou posfixa.
> Existe uma pasta com exemplos de entrada para o programa na raiz do projeto.
> Observação: Tanto no comando 1 quanto no 2 é necessário que o usuário passe o input exatamente como
> é demonstrado. Exemplo para uma expressão posfixa: `LER POSFIXA 3 4 +`. A separação em dois inputs do comando 1 ou 2 
> e da expressão a ser passada irá resultar em erro.
## Como utilizar o programa
> Após compilar o executável, você pode utilizar o programa de duas maneiras:
* Digite `make run` no terminal para executar o programa, que irá aguardar pelos inputs do usuário.
* Digite `make run < nomearquivo.txt` para executar o programa com um arquivo texto que já contém a expressão a ser manipulada. Certifique que o diretório do arquivo texto foi passado corretamente
* Digite `make run < ./exemplos-entrada/exemplos-entrada.txt` para executar um arquivo teste.