# Get Next Line (GNL) - 42 Porto

## 📝 Descrição

Get Next Line (GNL) é uma função em C que lê uma linha de um descritor de arquivo (file descriptor). Uma linha é uma sequência de caracteres terminada por uma quebra de linha (`\n`) ou pelo fim do arquivo (EOF). Este projeto é parte do currículo comum da 42 Network.

## 🎯 Objetivos

- Aprender sobre variáveis estáticas em C
- Aprender sobre alocação de memória
- Entender o conceito de file descriptors
- Melhorar a lógica de programação
- Implementar uma função útil para projetos futuros

## 📚 Como funciona

A função `get_next_line` tem a seguinte assinatura:

```c
char *get_next_line(int fd);
```

### Parâmetros
- `fd`: O file descriptor para ler

### Valor de Retorno
- A linha que foi lida (incluindo `\n` se presente)
- `NULL` se não houver mais nada para ler ou se ocorrer um erro

### Comportamento
- Chamadas sucessivas à função `get_next_line` permitem ler o arquivo apontado pelo file descriptor, uma linha por vez
- A função funciona tanto para ler de um arquivo quanto do stdin
- O valor de retorno inclui o caractere delimitador `\n`, exceto quando o fim do arquivo é alcançado

## 🛠️ Funções Permitidas

- `read`
- `malloc`
- `free`

## 💻 Como Compilar

```bash
# Compilar a função principal
cc -Wall -Wextra -Werror -c get_next_line.c

# Compilar as funções auxiliares
cc -Wall -Wextra -Werror -c get_next_line_utils.c

# Para usar com buffer size definido
cc -D BUFFER_SIZE=42 -c get_next_line.c
```

## 📖 Como Usar

```c
#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    fd = open("arquivo.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## ⚠️ Requisitos

- A função deve ser capaz de ler de múltiplos file descriptors sem perder o fio da leitura de cada um
- Todas as alocações de memória devem ser devidamente liberadas
- O projeto deve seguir a Norma da 42 (`norminette`)
- Não podem ocorrer leaks de memória

## 🔍 Testes

Para testar a função, você pode:

1. Criar diferentes arquivos de texto
2. Testar com diferentes BUFFER_SIZE
3. Testar com múltiplos file descriptors
4. Verificar leaks de memória usando Valgrind

```bash
valgrind --leak-check=full --show-leak-kinds=all ./a.out
```

## 📝 Notas

- A função deve ser capaz de lidar com qualquer tamanho de BUFFER_SIZE
- É importante liberar toda a memória alocada para evitar leaks
- A função deve ser resiliente a erros e comportamentos inesperados

## 🔗 Links Úteis

- [Manual do Read](https://man7.org/linux/man-pages/man2/read.2.html)
- [Documentação da 42](https://42.github.io/norminette/)
- [Valgrind](https://valgrind.org/docs/manual/quick-start.html)

## ⚖️ Licença

Este projeto é parte do currículo da 42 Network e deve seguir as diretrizes acadêmicas da escola.

---
© 2024 [Nuno Pereira] - 42 Porto
