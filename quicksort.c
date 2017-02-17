void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int n, array[n];

void qs(int* arr, int first, int last)
{
    int i = first;//создание копий переменных, с которыми будем работать
	int j = last;
	int center = arr[(first + last) / 2];//вычисляем центр, на который будем опираться.

    do {
        while (arr[i] < center) i++;//поиск значения больше центра
        while (arr[j] > center) j--;//поиск значения меньше центра
        if(i <= j) {
            if (arr[i] > arr[j]) swap(&arr[i], &arr[j]);//проверка счетчиков. если true, swap их.
            i++;//перевод счетчиков на след элемнты
            j--;
        }
    } while (i <= j);

    if (i < last)//если true, рекурсия
        qs(arr, i, last);//массив, исходное начало и текущий окнец
    if (first < j)//если true, рекурсия
        qs(arr, first, j);//массив, текущее начало и конец
}

//функция вызова
qs(array, 0, n - 1);
