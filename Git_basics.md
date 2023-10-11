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

Note 1) : After the ```git init``` command has been executed as part of the above sequence, git will
display the following messages;

```
hint: Using 'master' as the name for the initial branch. This default branch name
hint: is subject to change. To configure the initial branch name to use in all
hint: of your new repositories, which will suppress this warning, call:
hint:
hint:   git config --global init.defaultBranch <name>
hint:
hint: Names commonly chosen instead of 'master' are 'main', 'trunk' and
hint: 'development'. The just-created branch can be renamed via this command:
hint:
hint:   git branch -m <name>
Initialized empty Git repository in C:/Users/craig/Documents/GitHub/Javascript-Example-1/.git/
```

Note 2) : The ```git branch``` command is used to perform operations on branches.
By operations, we mean such tasks as creating, listing, renaming, and deleting branches. This command doesn't let you switch between branches or put a forked history back together again. For this reason, git branch is tightly integrated with the git checkout and git merge commands. 

Note 3) : If for whatever reason, you forget or neglect to set an upstream branch for your
local directory, git will fail and display the following message;

```
fatal: The current branch master has no upstream branch.
To push the current branch and set the remote as upstream, use

    git push --set-upstream origin master
```

![Image depicting Git branching.](../images/Git_branching_diagram.png)

#### + Check the status of a local repository
```
  > git status
```

#### + Add a local file to a local repository
```
  > git add <Name of file>
```
Example;
```
  > git add Filename.cpp
```

#### + Remove a file from a repository
```
  > git rm <Name of file>
```
Example;
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