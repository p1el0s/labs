template <typename T>
void push_back(T*&array, T value, int capacity)
{
	T* arraynew = new T[capacity + 1];
	for (int i = 0; i < capacity + 1; i++) {
		arraynew[i] = array[i];
	}
	arraynew[capacity] = value;
	delete[] array;
	array = arraynew;
	if (capacity + 1 > 100) {
		throw 1;
	}
}