# Crypt library

The crypt library is a lightweight cryptography library that allows the user to encrypt
binary data with a symmetric key. This project uses `cmake` to build and its the only
dependency of the project. This will ease porting to other architectures with commands
such as:

```
  cmake --build build --target -DCMAKE_C_COMPILER=<your-arm-favorite-flavor>
```

The library is also lightweigth and allows the use to use the encryption/decryption algorithm
according to its needs. Well suited to encrypt data on MCUs and resource constrained systems, for
it consists of only one file and header, also can be dynamically liked to any image you might want
to flash on your device.

More encryption algorithms could be implemented, but for the sake of quality the unit test will
provide with enough tests to prove your algorithm by calling:
```
  cmake --build build --target utest
```

## Crypt CLI

The `crypt_cli` tool is included to use on the terminal, it will use the library
algorithm to encrypt the given key in a hexadecimal format. The default usage of the
tool is to take an input, it could be a file, the stdin or even some piped data, encrypt
it and write it to stdout, a file or to pipe it out to another command. 
