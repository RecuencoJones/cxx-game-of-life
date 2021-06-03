## Statements

- Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
- Any live cell with more than three live neighbours dies, as if by overcrowding.
- Any live cell with two or three live neighbours lives on to the next generation.
- Any dead cell with exactly three live neighbours becomes a live cell.

## Setup

```
mkdir -p build && cd build
conan install ..
cmake ..
```

## Build && Run

```
make main
./bin/main
```

## Test

```
make test
./bin/test
```

## TDD

```
find ../src ../test | entr sh -c 'cmake ..; make test; ./bin/test'
```