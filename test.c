#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>


int main(void)
{
    int fd;
    char *line;

    // Abre o arquivo para leitura
    fd = open("text1.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }
    // Lê o arquivo linha por linha
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);  // Libera a memória da linha lida
    }
    close(fd);
    return (0);
}


/* TESTING INVALID FD */

// int main(void)
// {
//     char *line = get_next_line(42);
//     if (!line)
//         printf("Test passed: NULL returned for invalid FD\n");
//     else
//         printf("Test failed: Expected NULL, got '%s'\n", line);
//     return (0);
// }

/* ** TESTE PARA A FUNCAO ft_extract_line e ft_update_keep ** */
// int ft_find_newline(const char *str);
// char	*ft_substr(char *str, unsigned int start, size_t len);
// void	*ft_calloc(size_t nmemb, size_t size);

// int main(void)
// {
//     char *keep;
//     char *line;

//     // Exemplo: Buffer inicial com múltiplas linhas
//     keep = strdup("Hello, World!\nThis is a test.\nAnother line here.");
//     printf("Buffer inicial: %s\n", keep);

//     // Extrai a primeira linha
//     line = ft_extract_line(keep);
//     printf("\nLinha extraída: %s\n", line);

//     // Atualiza o buffer para o restante
//     keep = ft_update_keep(keep);
//     printf("Buffer restante após update: %s\n", keep);

//     // Extrai a próxima linha
//     free(line);
//     line = ft_extract_line(keep);
//     printf("\nPróxima linha extraída: %s\n", line);

//     // Atualiza o buffer novamente
//     keep = ft_update_keep(keep);
//     printf("Buffer restante após segundo update: %s\n", keep);

//     // Limpa memória usada
//     free(line);
//     free(keep);

//     return (0);
// }
/* ** TESTE PARA A FUNCAO ft_extract_line ** */

// int ft_find_newline(const char *str);
// char	*ft_substr(char *str, unsigned int start, size_t len);
// void	*ft_calloc(size_t nmemb, size_t size);

// int main()
// {
//     char *keep = "Hello World Goodbye, ciao tudo bem hey\n bro bro bro";
//     char *line;

//     // Testa a função
//     line = ft_extract_line(keep);
//     if (line)
//     {
//         printf("Linha extraída: %s\n", line);
//         free(line);  // Não se esqueça de liberar a memória
//     }
//     else
//     {
//         printf("Erro ao extrair linha.\n");
//     }

//     return 0;
// }

/* ** TESTE PARA A FUNCAO ft_find_newline ** */

// int ft_find_newline(const char *str);

// int main(void)
// {
//     // Casos de teste
//     char *test1 = "Hello\nWorld";
//     char *test2 = "Hello World"; //-1 pq nao tem /n
//     char *test3 = "\nHello World";
//     char *test4 = "Hello World\n";
//     char *test5 = ""; -1;

//     printf("Test 1: %s -> Newline at index: %d\n", test1, ft_find_newline(test1));
//     printf("Test 2: %s -> Newline at index: %d\n", test2, ft_find_newline(test2));
//     printf("Test 3: %s -> Newline at index: %d\n", test3, ft_find_newline(test3));
//     printf("Test 4: %s -> Newline at index: %d\n", test4, ft_find_newline(test4));
//     printf("Test 5: %s -> Newline at index: %d\n", test5, ft_find_newline(test5));

//     return 0;
// }
//TESTANDO A FUNCAO READ
// char *ft_read_file(int fd, char *keep)
// {
//     char    *buffer;
//     int     bytes_read;

//     printf("Entrando em ft_read_file\n");

//     // Aloca espaço para o buffer de leitura
//     buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
//     if (!buffer)
//     {
//         printf("Erro ao alocar memória para o buffer.\n");
//         return (NULL);
//     }

//     printf("Memória alocada para buffer com tamanho %d\n", BUFFER_SIZE);

//     while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
//     {
//         buffer[bytes_read] = '\0'; // Adiciona terminador nulo
//         printf("Bytes lidos: %d, Conteúdo do buffer: %s\n", bytes_read, buffer);

//         keep = ft_strjoin(keep, buffer); // Concatena ao conteúdo existente
//         if (!keep)
//         {
//             printf("Erro ao juntar strings em ft_strjoin.\n");
//             free(buffer);
//             return (NULL);
//         }
//     }

//     free(buffer);

//     if (bytes_read < 0)
//     {
//         printf("Erro ao ler o arquivo (bytes_read < 0).\n");
//         free(keep);
//         return (NULL);
//     }

//     printf("Saindo de ft_read_file com conteúdo: %s\n", keep);
//     return (keep);
// }
