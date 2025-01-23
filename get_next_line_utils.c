/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarcos <tmarcos@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:17:00 by tmarcos           #+#    #+#             */
/*   Updated: 2025/01/23 18:24:21 by tmarcos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}
char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	// Retorna uma string vazia caso o índice de início seja maior ou igual ao tamanho da string
	if (!str || start >= ft_strlen(str))
		return (ft_calloc(1, sizeof(char))); // Usa calloc para garantir memória limpa
	// Ajusta len para garantir que não ultrapasse o final da string
	if (len > ft_strlen(str + start))
		len = ft_strlen(str + start); 
	// Aloca memória para a substring
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	// Copia os caracteres da substring
	i = 0;
	while (i < len)
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0'; // Adiciona o terminador nulo
	return (sub);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;
	size_t	total_len;

	i = 0;
	while (s1 && s1[i])
		i++;
	j = 0;
	while (s2 && s2[j])
		j++;
	total_len = i + j;
	joined = (char *)malloc((total_len + 1) * sizeof(char));
	if (!joined)
		return (NULL);
	j = 0;
	total_len = 0;
	while (s1 && s1[j])
		joined[total_len++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		joined[total_len++] = s2[j++];
	joined[total_len] = '\0';
	free(s1);
	return (joined);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_bytes;
	size_t	i;
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	total_bytes = nmemb * size;
	if (total_bytes / nmemb != size)
		return (NULL);
	ptr = malloc(total_bytes);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_bytes)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

/* ft_strlen: Calcula e retorna o comprimento de uma string,
percorrendo-a até encontrar o caractere nulo \0.

ft_strchr: Busca pela primeira ocorrência de um caractere em uma string
 e retorna um ponteiro para essa posição.
 Se não encontrado, retorna NULL.
 Se o caractere procurado for \0,
 retorna o ponteiro para o final da string.

ft_substr Cria uma nova string com um segmento
 específico da string original, o que é perfeito 
 para extrair uma linha até o \n ou qualquer outra parte específica.
é ideal para manipulação de buffers grandes, pois permite 
que você trabalhe com partes específicas da string
 de forma eficiente, sem sobrecarregar a memória
  com dados desnecessários. Além disso, isso
   ajuda no desempenho geral, já que você está
    sempre lidando apenas com os dados que 
    são necessários em cada etapa.

ft_strjoin: Concatena duas strings.
 Aloca memória para a nova string,
 copia o conteúdo das duas strings para a nova alocação
 e retorna a string concatenada.

ft_calloc: Aloca memória para nmemb elementos de tamanho size
e inicializa a memória com zeros.
Retorna o ponteiro para a memória alocada ou NULL em caso de erro
 (como falha de alocação ou overflow). */
