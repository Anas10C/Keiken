## 1. Read/Write permissions without delete permissions

In order to grant read/write permissions to a file while also denying the permission to delete it,
one must grant only read/execute permissions to the user on the parent directory (deny write permission on it) while also granting read/write permissions on the file

```
mkdir testdir && touch testdir/test.txt
```

```
chmod o-w testdir && chmod o=rw testdir/test.txt
```

## 2. Read/Delete permissions without write permissions

Pretty much the same steps just the other way around.

```
chmod o=rwx testdir && chmod o-w testdir/test.txt
```

## 3. Is it practical?

Honestly I can't really imagine any practical uses for it without more context.
Maybe in the case of a program that depends on a file to run without failing, it could prove to be useful.
The other case just doesn't make any sense.