#include "Structs.h"

void print_records(Student* arr, int size)
{
	for (int index = 0; index < size; ++index)
	{
		printf("arr[%d]: %s, %s, %u, %.2lf\n", index, arr[index].last,
			arr[index].first, arr[index].id, arr[index].gpa);
	}
}