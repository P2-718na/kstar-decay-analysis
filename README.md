<div align="center">
  <img alt="Alma Mater Studiorum Logo" src="assets/unibo-logo.png">
</div>

# kstar-decay-analysis
This is my project for my Physics laboratory-2 course at University of Bologna.

## Dependencies
- [ROOT](https://root.cern/) (required, version 6.18^)
- [pipenv](https://pipenv.pypa.io/en/latest/) (required)

## Running
This code was tested and running on _Mac OS X 10.14.6 Mojave_ and _Windows 10_.

### Set-up Jupyter
After installing dependencies, `cd` in the source code directory and run
```shell
pipenv install
```
to install modules.

### Launch Jupyter Lab
Run
```shell
pipenv run jupyter-lab
```
to launch jupyter. If it doesn't open by itself, follow the link on the
console.

### Troubleshooting
If there is a permission error on wsl, just `chown` the needed files/directories.

## Additional notes
Don't use `root --notebook`, it's buggy.

Also note that c++ root kernel is slow at loading. Have patience.
