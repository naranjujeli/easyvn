# easyvn

## Recommended: Create an authentication file for SVN

Go to `~/.subversion/auth/svn.simple`. There should already be a file created automatically by SVN in order to store your credentials for a particular repository. Make sure its contents look exactly like the following:

```
K 8
passtype
V 6
simple
K 8
password
V <STRING_CHARACTER_COUNT>
<YOUR_PASSWORD>
K 15
svn:realmstring
V <STRING_CHARACTER_COUNT>
<AUTHENTICATION_REALM>
K 8
username
V <STRING_CHARACTER_COUNT>
<YOUR_USERNAME>
END
```

You can get the "Authentication realm" by running this command inside the repository folder:

```
$ svn auth
```

Now change its permissions by running:

```
$ chmod 700 <FILE_PATH>
```

Starting a new shell after these steps should be enough for Subversion to never ask again for your password for that repository.
