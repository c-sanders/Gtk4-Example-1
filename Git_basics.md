## git basics


#### + Get help for git in general
```
  > git help
```


#### + Get help for a particular git command
```
  > git <Name of command> -h
```
Example;
```
  > git commit -h
```


#### + Initialise a directory to hold a local copy of a repository
```
  > git init
```


#### + Clone a remote repository into a local directory
```
  > git clone <URI of remote repository>
```
Example;
```
  > git clone https://github.com/c-sanders/Gtk4-Example-1.git
```
Note that this will create a sub-directory called ```Gtk4-Example-1``` within
the current working directory and then clone the contents of the remote
repository into this sub-directory.  


#### + Configure a local directory to be a copy of a GitHub repository
In order to do this, the sequence of steps below need to be followed. 
```
  > git init
  > git add README.md
  > git commit -m "Commit comment."
  > git branch -M main
  > git remote add origin https://github.com/c-sanders/GitHub-Repository.git
  > git push -u origin main
```

Note that the ```git branch``` command can be used to create, list, rename, and delete branches. It doesn't let you switch between branches or put a forked history back together again. For this reason, git branch is tightly integrated with the git checkout and git merge commands. 

#### + Check the status of a local repository
```
  > git status
```

#### + Add a local file to a local repository
```
  > git add Filename.cpp
```

#### + Remove a file from a repository
```
  > git rm Filename.cpp
```

#### + Commit changes, i.e. additions and removals of files, to the local repository
Will this "stage" the changes, and make them ready and waiting to be pushed to
the remote repository?
```
  > git commit -m "Commit comment."
```

#### + Pushing locally committed changes to a remote repositoy
```
  > git push
```
or
```
  > git push origin master
```