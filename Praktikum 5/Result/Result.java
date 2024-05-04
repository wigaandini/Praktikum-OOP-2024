// Erdianti Wiga Putri Andini
// 13522053

public class Result<T, E extends Exception> implements IResult<T, E> {
    private T data;
    private E error;
  
    // constructor
    public Result(T data, E error) {
        this.data = data;
        this.error = error;
    }
    
    // return new Result object with data based on input
    public static <T, E extends Exception> Result<T, E> ok(T data) {
        return new Result<T, E>(data, null);
    }
  
    // return new Result object with error based on input
    public static <T, E extends Exception> Result<T, E> err(E error) {
        return new Result<T, E>(null, error);
    }
  
    // implement all other functions in the interface
    // returns true if the result data is not null
    public boolean isOk() {
        return data != null;
    }
  
    // returns true if the result Err is not null
    public boolean isErr() {
        return error != null;
    }
  
    // returns the data if the result is Ok, otherwise throws the error
    public T unwrap() throws Exception {
        if (isOk()) {
            return data;
        } else {
            throw error;
        }
    }
  
    // returns the data if the result is Ok, otherwise returns the default value
    public T unwrapOrElse(T defaultValue) {
        if (isOk()) {
            return data;
        } else {
            return defaultValue;
        }
    }
  
    // returns the data if the result is Ok, otherwise throws the default exception
    public T unwrapOrThrow(Exception defaultException) throws Exception {
        if (isOk()) {
            return data;
        } else {
            throw defaultException;
        }
    }
  }