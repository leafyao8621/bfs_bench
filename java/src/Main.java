import core.Runner;

class Main {
    public static void main(String[] args) {
        try {
            Runner r = new Runner(args[0]);
            r.run(Boolean.parseBoolean(args[1]),
                  Boolean.parseBoolean(args[2]),
                  Boolean.parseBoolean(args[2]));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
