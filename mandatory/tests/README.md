# miniRT Parser Tester

## Usage

### 1. Generate Tests
Creates `valid/` and `invalid/` folders with 45 test `.rt` files. Run this inside the `test/` directory.
```bash
./generate_tests.sh
```

### 2. Run Tests
Executes your `miniRT` binary against every test file using the `-t` flag.
```bash
./tester.sh
```

### 3. Clean Up
Deletes the test folders and all generated files to keep your repository clean.
```bash
./generate_tests.sh -g
```