/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:17:22 by tmarcos           #+#    #+#             */
/*   Updated: 2025/01/23 23:13:15 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ft_find_newline - Encontra o índice da primeira ocorrência de '\n' em uma string.
 * str: A string na qual procura o caractere.
 * Retorna:
 * - O índice da primeira ocorrência de '\n', se encontrado.
 * - -1, se não houver '\n' na string.
 * 
 * ft_extract_line - Extrai a linha de `keep` até o primeiro '\n'.
 * keep: A string de onde a linha será extraída.
 * Retorna:
 * - A linha extraída até o primeiro '\n' (inclusive), ou a string toda se não houver '\n'.
 * - NULL se a string for vazia ou a memória não puder ser alocada.
 * 
 * * ft_update_keep - Atualiza o buffer 'keep' com o conteúdo restante após o '\n'.
 * @keep: O buffer atual contendo os dados lidos.
 * Retorna:
 * - Uma nova string com o conteúdo restante após o '\n'.
 * - NULL se não houver mais conteúdo restante.
 * 
 * * ft_read_file - Lê dados de um file descriptor e atualiza o buffer 'keep'.
 * @fd: File descriptor a ser lido.
 * @keep: Buffer atual contendo dados não processados. 
 * Retorna:
 * - O buffer atualizado com o conteúdo lido do arquivo.
 * - NULL em caso de erro ou se não houver mais dados a serem lidos.
 * Detalhes:
 * - A função usa o buffer temporário para ler blocos
 *  de dados do arquivo.
 * - Garante que 'keep' seja atualizado e o conteúdo 
 * não processado seja preservado.
 *
 * * get_next_line - Lê uma linha de um arquivo a partir
 *  de um file descriptor.
 * @fd: O file descriptor do arquivo a ser lido.
 * Retorna:
 * - Uma string contendo a próxima linha do arquivo, incluindo o '\n', se houver.
 * - NULL em caso de erro, fim de arquivo ou se não houver mais linhas a serem lidas.
 * Detalhes:
 * - A função utiliza um buffer estático para armazenar os dados não processados entre chamadas consecutivas.
 * - Lida com diferentes tamanhos de BUFFER_SIZE definidos durante a compilação.
 * - Garante que a memória seja gerenciada de forma eficiente, com limpeza de dados obsoletos.
 * Comportamento esperado:
 * - Chamada repetida à função retorna uma linha por vez do arquivo.
 * - Ao atingir o final do arquivo, retorna NULL.
 * - A função é robusta para lidar com arquivos pequenos, grandes, vazios ou sem '\n'.
 * 
 */

#include "get_next_line.h"
#include <stdio.h>

int	ft_find_newline(const char *str)
{
	int i;
	// Verificação de ponteiro nulo
	if (!str)
		return (-1);

	// Percorre a string procurando por '\n'
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i); // Retorna o índice se encontrar '\n'
		i++;
	}
	// Retorna -1 se não encontrar '\n'
	return (-1);
}

char    *ft_extract_line(char *keep)
{
	char    *line;
	int     newline_index;

	// Verifica se keep é nulo
	if (!keep)
		return (NULL);
	// Chama ft_find_newline para obter a posição do '\n'
	newline_index = ft_find_newline(keep);
	// Se não encontrar '\n', usa ft_substr para duplicar toda a string
	if (newline_index == -1)
		return (ft_substr(keep, 0, ft_strlen(keep)));
	// Se encontrar '\n', usa ft_substr para pegar a linha até o '\n' (inclusive)
	line = ft_substr(keep, 0, newline_index + 1);
	return (line);
}

char    *ft_update_keep(char *keep)
{
	char    *new_keep;
	int     newline_index;

	// Verifica se keep é nulo
	if (!keep)
		return (NULL);
	// Encontra a posição do '\n' em keep
	newline_index = ft_find_newline(keep);
	// Se não houver '\n' ou não há conteúdo restante, libera keep e retorna NULL
	if (newline_index == -1 || keep[newline_index + 1] == '\0')
	{
		free(keep);
		return (NULL);
	}
	// Cria o novo buffer com o conteúdo após o '\n'
	new_keep = ft_substr(keep, newline_index + 1, ft_strlen(keep) - (newline_index + 1));
	if (!new_keep) // Falha na alocação
	{
		free(keep);
		return (NULL);
	}
	// Libera o buffer antigo
	free(keep);
	return (new_keep);
}

char *ft_read_file(int fd, char *keep)
{
    char    *buffer;
    int     bytes_read;

    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) // Lê até o final do arquivo
    {
        buffer[bytes_read] = '\0'; // Adiciona terminador nulo
        keep = ft_strjoin(keep, buffer); // Concatena ao conteúdo existente
        if (ft_find_newline(keep) != -1)
            break;
        if (!keep)
        {
            free(buffer);
            return (NULL); // Erro ao juntar strings
        }
    }
    free(buffer);
    if (bytes_read < 0)
    {
        free(keep);
        return (NULL);
    }
    return (keep);
}

char	*get_next_line(int fd)
{
	static char	*keep;
	char		*line;

	// Verifica se o file descriptor é válido
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// Lê os dados do arquivo e atualiza o buffer
	keep = ft_read_file(fd, keep);
	// Se houver erro ou fim de arquivo, retorna NULL
	if (!keep)
		return (NULL);
	// Extrai a linha até o '\n'
	line = ft_extract_line(keep);
	// Atualiza o buffer para o restante do conteúdo após o '\n'
	keep = ft_update_keep(keep);
	// Retorna a linha extraída
	return (line);
}

// ESSA EH A FUNCAO QUE TAVA PASSANDO OS TESTES MENOS NO BUFFER 42

// char *ft_read_file(int fd, char *keep)
// {
// 	char    *buffer;
// 	int     bytes_read;

// 	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!buffer)
// 		return (NULL);
// 	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) // Lê até o final do arquivo
// 	{
// 		buffer[bytes_read] = '\0'; // Adiciona terminador nulo
// 		keep = ft_strjoin(keep, buffer); // Concatena ao conteúdo existente
// 		if (!keep)
// 		{
// 			free(buffer);
// 			return (NULL); // Erro ao juntar strings
// 		}
// 	}
// 	free(buffer);
// 	if (bytes_read < 0)
// 	{
// 		free(keep);
// 		return (NULL);
// 	}
// 	return (keep);
// }
