# guidgen

guidgen is a guid generator command line tool.

# Usage

```
guidgen [--format Format] [--count Count]
```

The options are:

```
-f, --format  : Indicates how to format the value of this Guid. The format parameter can be :
                  N : 32 digits.
                  D : 32 digits separated by hyphens.
                  B : 32 digits separated by hyphens, enclosed in braces.
                  P : 32 digits separated by hyphens, enclosed in parentheses.
                  X : Four hexadecimal values enclosed in braces, where the fourth value is a subset of eight hexadecimal values that is also enclosed in braces.
-c, --count   : indicate the number of generation (form 1 to 2147483647)
-v, --version : Shows version information.
-h, --help    : Shows this help page.
```

# Some examples

## generate one guid with 32 digits separated by hyphen format

Open "Command Prompt" or "Terminal", and type the following:

```bash
guidgen
```

or

```bash
guidgen --format D
```

Example output

```
372812f1-0472-4d87-9954-738f7cc2b213
```

## generate ten guids with Four hexadecimal values enclosed in braces, where the fourth value is a subset of eight hexadecimal values that is also enclosed in braces.

Open "Command Prompt" or "Terminal", and type the following:

```bash
guidgen --count 10 --format X
```

Example output

```
{0xbfeb4bbb,0xb142,0x4b4d,{0x96,0xb7,0x46,0x42,0xe9,0x91,0x83,0x65}}
{0xe5f9c6d6,0x21ef,0x46ef,{0xba,0xfe,0x2a,0x46,0xde,0x8d,0x13,0x0f}}
{0x6a1b8aaf,0x24fa,0x4f4e,{0x8b,0x3d,0x4d,0x2f,0x03,0xe5,0xb1,0x54}}
{0xbfbd8bfb,0x4b27,0x41d0,{0xa5,0x95,0x8e,0x50,0x93,0x8f,0x3b,0xe3}}
{0x61079309,0xaf50,0x4262,{0xa1,0xf4,0x72,0xf1,0xb4,0x63,0xc1,0x8a}}
{0x33f7e5ee,0xcfef,0x4e4d,{0x95,0xe9,0xa8,0x98,0xcc,0xc2,0x36,0x1a}}
{0xe073d32c,0xa9c6,0x4f2e,{0xb0,0x33,0x48,0x26,0x8a,0x3e,0x3e,0xaa}}
{0x88ff845e,0x210c,0x4e43,{0xa9,0x7a,0x0e,0xf3,0x9f,0xc1,0xad,0x08}}
{0x23ed1748,0x13b1,0x493e,{0x88,0x94,0xfa,0x4e,0xda,0x59,0xc9,0x5f}}
{0x9b7967b8,0xadda,0x42d7,{0x87,0x11,0xa7,0x15,0x48,0x40,0xbc,0x56}}
```

# For more info about guidgen

Open "Command Prompt" or "Terminal", and type the following:

```bash
guidgen --help
```

______________________________________________________________________________________________

© 2025 Gammasoft.
