## README.md file for project Gtk4 Example 1


There are a number of tools which one can use to interact with Git or GitHub. Two of them
are the Git command line interface (git) and the GitHub command line interface (gh).

The git utility allows you to work with both local and remote Git repositories - including Git
repositories which are hosted on GitHub. The GitHub command line interface on the other hand,
is specifically for working with GitHub.

We will refer to both of these command line utilities - git and gh, here in this discussion

#### - Initialise a directory to hold a local copy of a repository
```
  > git init
```

* #### Cloning a remote repository into a local directory

Example using git;
```
  > git clone https://github.com/c-sanders/Gtk4-Example-1.git
```

Example using gh;
```
  > gh repo clone c-sanders/ImaginaryNumbers
```

* #### Check the status of a local repository
```
  > git status
```

* #### Add a local file to a local repository
```
  > git add Filename.cpp
```

* #### Remove a file from a repository
```
  > git rm Filename.cpp
```

* #### Commit changes, i.e. additions and removals of files, to the local repository
```
  > git commit -m "Commit comment."
```

* #### Pushing locally committed changes to a remote repositoy
```
  > git push
```
or
```
  > git push origin master
```