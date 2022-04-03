template <typename T>
void f(T* mas, int size) {
	if (size % 2 == 1) {
		throw 1;
	}
	else {
		T temp = 0;
		for (int i = 0; i != size / 2; i++) {
			temp = mas[i];
			mas[i] = mas[size - i - 1];
			mas[size - i - 1] = temp;
		}
	}
}
