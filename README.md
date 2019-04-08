# se-02-team-09
Development Environment: Qt Creator

## Build
```
$ cd se-02-team-09/Pencil-Producer/
$ mkdir build
$ cd build/
$ cmake .. && make
$ ./pencilproducer
```
## Documentation
Prebuilt documentation can be read by:
```
$ cd doc/html
$ browser index.html
```
To build documentation from scratch:
```
$ cd doc
$ doxygen
$ cd html
$ browser index.html
```

## Testing
Test cases can be found in:
```
$ Test/tst_test.cpp
```
### Build Test Cases
```
$ cd Test/
$ mkdir build/
$ cd build/
$ cmake .. && make
$ ./testpencils
```
## Developers
* Fezi Manana
* Ganbold Adilbish

