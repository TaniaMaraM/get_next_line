// #include "get_next_line.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <fcntl.h>


// char    *ft_read_file(int fd, char *keep);
// void	*ft_calloc(size_t nmemb, size_t size);
// char    *ft_strjoin(char *s1, char *s2);
// int     ft_find_newline(const char *str);

// #include "get_next_line.h"
// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
//     int fd;
//     char *line;

//     // Abre o arquivo para leitura
//     fd = open("test.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Erro ao abrir o arquivo");
//         return (1);
//     }

//     // Lê o arquivo linha por linha
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("Linha lida: %s", line);
//         free(line);  // Libera a memória da linha lida
//     }

//     // Fecha o arquivo
//     close(fd);
//     return (0);
// }

// int main(void)
// {
//     int     fd;
//     char    *result;
//     char    *keep = NULL;

//     // Abre o arquivo
//     fd = open("text_file1.txt", O_RDONLY);
//     if (fd < 0)
//     {
//         perror("Erro ao abrir o arquivo");
//         return (1);
//     }

//     printf("Arquivo aberto com sucesso! FD: %d\n", fd);

//     // Testa ft_read_file
//     result = ft_read_file(fd, keep);
//     if (!result)
//     {
//         printf("Erro ao ler o arquivo.\n");
//         close(fd);
//         return (1);
//     }

//     // Imprime o resultado lido
//     printf("Conteúdo lido:\n%s\n", result);

//     // Libera a memória e fecha o arquivo
//     free(result);
//     close(fd);
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
