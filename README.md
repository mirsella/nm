# ft_nm

Small reimplementation of the Unix `nm` tool for ELF binaries.

Supported flags in this version: `-a`, `-g`, `-u`, `-p`, and `-r`.

## How It Works

The program opens a target file, validates the ELF header, memory-maps it, and then follows either the 32-bit or 64-bit parsing path. From there it finds the symbol table, resolves the associated string table, computes a display type for each symbol, sorts the results, and prints them.

This implementation is focused on ELF symbol-table parsing rather than matching every feature of the system `nm`.

## Build

```bash
make
```

## Run

```bash
./ft_nm /bin/ls
```

## Notes

- Defaults to `a.out` when no file is provided.
- ELF only.
- Includes sample binaries in `binary/` for manual testing.
