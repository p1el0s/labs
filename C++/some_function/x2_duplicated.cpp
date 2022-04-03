template <typename T>
void f(T*& mas, int size) {
	if (size * 2 > 100) {
		throw 1;
	}
	else {
		T* temp = new T[size*2];
		for (int i = 0; i != size*2; i++) {
			temp[i] = mas[i % size];
		}
		delete[] mas;
		mas = temp;
	}
}
