public class MirrorMatrix extends Matrix {
	public MirrorMatrix(int n, int c) {
		super(n, 1);
		column = c;
	}

	public void setElement(int i, int c, int b) {
		arr[i][0] = b;
	}

	public int getElement(int b, int c) {
		return arr[b][0];
	}
}
