// Erdianti Wiga Putri Andini
// 13522053

import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;

public class Streamer<T> implements IStreamer<T> {

    private List<T> data;

    public Streamer(List<T> data) {
        this.data = new ArrayList<>(data);
    }

    @Override
    public List<T> collect() {
        return new ArrayList<>(data);
    }

    @Override
    public void forEach(Function<T, Void> consumer) {
        for (T item : data) {
            consumer.apply(item);
        }
    }

    @Override
    public <R> IStreamer<R> map(Function<T, R> mapper) {
        List<R> mappedData = new ArrayList<>();
        for (T item : data) {
            mappedData.add(mapper.apply(item));
        }
        return new Streamer<>(mappedData);
    }

    @Override
    public IStreamer<T> filter(Function<T, Boolean> predicate) {
        List<T> filteredData = new ArrayList<>();
        for (T item : data) {
            if (predicate.apply(item)) {
                filteredData.add(item);
            }
        }
        return new Streamer<>(filteredData);
    }

    @Override
    public <R> R reduce(R initialValue, Function<R, Function<T, R>> reducer) {
        R res = initialValue;
        for (T item : data) {
            res = reducer.apply(res).apply(item);
        }
        return res;
    }

    @Override
    public <R> IStreamer<R> flatMap(Function<T, IStreamer<R>> mapper) {
        List<R> flatMapped = new ArrayList<>();
        for (T item : data) {
            flatMapped.addAll(mapper.apply(item).collect());
        }
        return new Streamer<>(flatMapped);
    }
    

    @Override
    public T findFirst(Function<T, Boolean> predicate) {
        for (T item : data) {
            if (predicate.apply(item)) {
                return item;
            }
        }
        return null;
    }

    @Override
    public T findLast(Function<T, Boolean> predicate) {
        for (int i = data.size() - 1; i >= 0; i--) {
            if (predicate.apply(data.get(i))) {
                return data.get(i);
            }
        }
        return null;
    }

    @Override
    public T head() {
        if (data.isEmpty()) {
            return null;
        }
        return data.get(0);
    }

    @Override
    public IStreamer<T> tail() {
        if (data.isEmpty()) {
            return new Streamer<>(new ArrayList<>());
        }
        return new Streamer<>(data.subList(1, data.size()));
    }

    @Override
    public T last() {
        if (data.isEmpty()) {
            return null;
        }
        return data.get(data.size() - 1);
    }

    @Override
    public IStreamer<T> init() {
        if (data.isEmpty()) {
            return new Streamer<>(new ArrayList<>());
        }
        return new Streamer<>(data.subList(0, data.size() - 1));
    }

    @Override
    public IStreamer<T> takeFirst(int n) {
        List<T> taken = new ArrayList<>();
        for (int i = 0; i < Math.min(n, data.size()); i++) {
            taken.add(data.get(i));
        }
        return new Streamer<>(taken);
    }

    @Override
    public IStreamer<T> takeLast(int n) {
        List<T> taken = new ArrayList<>();
        int start = Math.max(0, data.size() - n);
        for (int i = start; i < data.size(); i++) {
            taken.add(data.get(i));
        }
        return new Streamer<>(taken);
    }

    @Override
    public Boolean isEmpty() {
        return data.isEmpty();
    }

    @Override
    public Integer count() {
        return data.size();
    }

    @Override
    public Boolean some(Function<T, Boolean> predicate) {
        return data.stream().anyMatch(predicate::apply);
    }

    @Override
    public Boolean every(Function<T, Boolean> predicate) {
        return data.stream().allMatch(predicate::apply);
    }

    @Override
    public void reverse() {
        List<T> reversed = new ArrayList<>(data);
        for (int i = 0; i < data.size(); i++) {
            data.set(i, reversed.get(reversed.size() - i - 1));
        }
    }
}
