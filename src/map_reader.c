#include "../inc/header.h"
#include "../inc/map.h"

// [checked]
t_list	*read_map(char *filename)
{
	t_list	*head;
	t_list	*node;
	char	*line;
	int		fd;

	head = NULL;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (!head)
			head = ft_lstnew(line);
		else
		{
			node = ft_lstnew(line);
			ft_lstadd_back(&head, node);
		}
		line = get_next_line(fd);
	}
	return (head);
}
