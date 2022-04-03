class Matrix{
	private int[][] arr;
	private int size;
	Matrix(int n) {
		size = n;
		arr = new int[n][n];
		for(int i = 0; i < size; i++)
			for(int z = 0; z < size; z++)
				if(i == z) arr[i][i] = 1;
	}

	void clearMatrix() {
		for(int i = 0; i < size; i++)
				for(int z = 0; z < size; z++)
					arr[i][z] = 0;
	}

	Matrix(Matrix a) {
		this.arr = a.arr;
		this.size = a.size;
	}

	void setElement(int row, int column, int value) {
		arr[row][column] = value;
	}

	int getElement(int row, int column) {
		return arr[row][column];
	}

	Matrix product(Matrix a) {
		Matrix temp = new Matrix(a.size);
		temp.clearMatrix();
		for(int i = 0; i < size; i++)
			for(int z = 0; z < size; z++)
				for(int b = 0; b < size; b++)
					temp.arr[i][z] += this.arr[i][b] * a.arr[b][z];
		return temp;
	}

	Matrix sum(Matrix a) {
		Matrix temp = new Matrix(a.size);
		temp.clearMatrix();
		for(int i = 0; i < size; i++)
			for(int z = 0; z < size; z++)
					temp.arr[i][z] += this.arr[i][z] + a.arr[i][z];
		return temp;
	}

	void swap(int x, int y) {
		int temp = getElement(x+1, x);
		setElement(x+1, x, getElement(y+1,y));
		setElement(y+1, y, temp);
	}

	Matrix mirror(int x) {
		Matrix temp = new Matrix(this.size);
		temp.clearMatrix();
		int z = 0;
		if(x == 1) {for(int i = 0; i < this.size; i++) {
			for(int g = this.size - 1; g != -1; g--) {
				temp.arr[i][z] = this.arr[i][g];
				if(z != this.size - 1) z++;
			}
			z = 0;
		} }
		if (x == 2) {
			for(int i = this.size - 1; i != - 1; i--) {
			for(int g = 0; g < this.size; g++) {
				temp.arr[z][g] = this.arr[i][g];
			}
			if(z != this.size - 1) z++;
		}
		}
		return temp;
	}

	public String toString() {
		StringBuilder s = new StringBuilder();
		for (int i = 0; i < this.size; i++) {
			for(int z = 0; z < this.size; z++)
				s.append(arr[i][z] + " ");
			s.append('\n');
		}
		return s.toString();
	}
}
