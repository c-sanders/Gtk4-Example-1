## Downloading, configuring, and installing Qt on Linux.


* #### Using the apt Package Manager.

You can use the apt Package Management tool to download and install the Qt
package. 

To do so, issue the following command from a command line.

```
sudo apt install qtk-base-dev
```

Using this command, the Qt package may get installed into the following locations;

```
/usr/include/x86_64-linux-gnu/qt6
/usr/lib/x86_64-linux-gnu/qt6
```


* #### Downloading Qt from GitHub.

Alternatively, you can use git to download the Qt package from GitHub.

To do so, issue the following command from a command line. 

````
git clone git://code.qt.io/qt/qt5.git
````

Then, cd into the directory which the Qt package was just downloaded into and
invoke the following script;

```
./init-repository
```
