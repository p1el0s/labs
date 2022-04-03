template <typename T>
void func(T*&mas, int size) {
	if (size % 3 != 0) {
		throw 1;
	}
	int newsize = (size / 3) + size;
	T* temp = new T[newsize];
	for (int i = 0, sizen = 0; i < size; i++) {
		if (i % 3 == 2) {
			temp[i + sizen] = mas[i];
			sizen++;
			temp[i + sizen] = mas[i];
		}
		else {
			temp[i + sizen] = mas[i];
		}
	}
	delete[] mas;
	mas = temp;
}
