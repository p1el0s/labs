public class MyException extends RuntimeException {
	private String string;
	public MyException(String ex) {
		super(ex);
		string = ex;
	}
	public final String get() {
		return string;
	}
}
