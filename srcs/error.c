#include "../includes/nm.h"

void empty_file(t_file *file) {
	if (file->data)
		munmap(file->data, file->data_size);
	if (file->symbols)
		ft_lstclear(&file->symbols, free);
	if (file->fd > 0) {
		close(file->fd);
		file->fd = -1;
	}
}
