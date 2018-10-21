# mixsqp: R package for fast maximum-likelihood estimation of mixture proportions using sequential quadratic programming

[![Travis Build Status](https://travis-ci.org/stephenslab/mixsqp.svg?branch=master)](https://travis-ci.org/stephenslab/mixsqp)
[![Appveyor Build status](https://ci.appveyor.com/api/projects/status/i8744qet66w5uhe2?svg=true)](https://ci.appveyor.com/project/pcarbo/mixsqp)
[![codecov](https://codecov.io/gh/stephenslab/mixsqp/branch/master/graph/badge.svg)](https://codecov.io/gh/stephenslab/mixsqp)

The mixsqp R package provides algorithms based on [sequential
quadratic programming][sqp] for maximum likelihood estimation of the
mixture proportions in a finite mixture model where the component
densities are known. The SQP algorithm is expected to obtain solutions
that are at least as accurate as the state-of-the-art MOSEK
interior-point solver (called via the "KWDual" function in the
[REBayes package][rebayes]), and is expected to compute these
solutions much more quickly in large data sets.

For more details on the SQP algorithm, please see [our paper on
arXiv][arxiv-paper].

See also the [Julia implementation][mixsqp-julia], which is currently
faster than the R implementation, particularly for large data sets.

If you find a bug, or you have a question or feedback on our work,
please post an [issue][issues].

## Citing this work

If you find the mixsqp package or any of the source code in this
repository useful for your work, please cite our paper:

> Youngseok Kim, Peter Carbonetto, Matthew Stephens and Mihai
> Anitescu. *A fast algorithm for maximum likelihood estimation of
> mixture proportions using sequential quadratic programming.*
> [arXiv:1806.01412][arxiv-paper].

## License

Copyright (c) 2017-2018, Youngseok Kim, Peter Carbonetto, Matthew
Stephens and Mihai Anitescu.

All source code and software in this repository are made available
under the terms of the
[MIT license][mit-license]. See
file [LICENSE](LICENSE) for the full text of the license.

## Quick Start

Install the latest version of the mixsqp package from GitHub. (See
"Setup" below for more detailed package installation instructions.)

```R
devtools::install_github("stephenslab/mixsqp",
                         build_vignettes = TRUE,
                         upgrade_dependencies = FALSE)
```

Once you have installed the package, load the package in R:

```R
library(mixsqp)
```

Next, run the small example provided with the mixsqp function:

```R
example("mixsqp")
```

For a more detailed illustration of the SQP algorithm applied to
the problem of computing maximum-likelihood estimates for a mixture
model, work through the introductory vignette:

```R
vignette("mixsqp-intro")
```

To learn more, visit the [package website][mixsqp-website], or view the
"mixsqp" help page:

```R
help("mixsqp")
```

## Setup

To install the latest version of the mixsqp package from GitHub,
use [devtools][devtools]:

```R
install.packages("devtools")
library(devtools)
install_github("stephenslab/mixsqp",build_vignettes = TRUE,
               upgrade_dependencies = FALSE)
```

This command should automatically install all required packages if
they are not installed already.

Alternatively, if you have cloned the repository locally, you can
install the package with the `install_local` function from
devtools. Assuming your working directory contains the mixsqp
repository, run this code to install the package:

```R
library(devtools)
list.files(pattern = "mixsqp") # Should output "mixsqp".
install_local("mixsqp",build_vignettes = TRUE,upgrade_dependencies = FALSE)
```

### Additional setup notes

+ Compiling the mixsqp package from source will require a C++ compiler
setup that is appropriate for the the R installed on your
computer. For details, refer to the [CRAN documentation][cran]. For
Mac computers, see [these notes][compiling-macos].

+ To use the (optional) alternative solver, "mixkwdual", you will need
to install the [REBayes][rebayes] package which, in turn, requires the
[Rmosek][mosek] package. Refer to the
[MOSEK documentation][mosek-docs] for instructions on installing the
Rmosek package. Once you have followed these steps, you can run
[this example](inst/code/test.rmosek.R) to verify that Rmosek is
correctly installed.

## Developer notes

### Testing the package

To install and test the mixsqp R package, run the following commands
in the shell:

```bash
R CMD build mixsqp
R CMD INSTALL mixsqp_0.1-62.tar.gz
R CMD check --as-cran mixsqp_0.1-62.tar.gz
```

Note that these commands require that the dependencies have already
been installed. See the [DESCRIPTION](DESCRIPTION) file for details.

### Updating the C++ source and documentation

When any changes are made to [roxygen2][roxygen2] markup or to the C++
code in the src directory, simply run `devtools::document()` to 
update the [RcppExports.cpp](src/RcppExports.cpp), the NAMESPACE file,
and the package documentation files in the man directory.

### Updating the pkgdown site

Run this line of R code to build the website (make sure you have an
Internet connection while running the code):

```R
pkgdown::build_site(mathjax = FALSE)
```

### Other developer notes

+ Add file `pre-commit` to `.git/hooks` in the git repository to
prevent commits that don't include a change to the package version.

## Credits

This project was developed by [Youngseok Kim][youngseok] at the
[University of Chicago][uchicago], with contributions from
[Peter Carbonetto][peter], [Matthew Stephens][matthew] and
[Mihai Anitescu][mihai].

[mixsqp-website]: https://stephenslab.github.io/mixsqp
[sqp]: https://neos-guide.org/content/sequential-quadratic-programming
[arxiv-paper]: https://arxiv.org/abs/1806.01412
[mixsqp-julia]: https://github.com/stephenslab/mixsqp-paper
[issues]: https://github.com/youngseok-kim/mixsqp/issues
[rebayes]: https://cran.r-project.org/package=REBayes
[mosek]: https://www.mosek.com
[mosek-docs]: https://www.mosek.com/documentation
[uchicago]: https://www.uchicago.edu
[youngseok]: https://github.com/youngseok-kim
[peter]: https://pcarbo.github.io
[matthew]: http://stephenslab.uchicago.edu
[mihai]: http://www.mcs.anl.gov/~anitescu
[mit-license]: https://opensource.org/licenses/mit-license.html
[devtools]: https://github.com/r-lib/devtools
[roxygen2]: https://cran.r-project.org/package=roxygen2
[cran]: https://cran.r-project.org
[compiling-macos]: https://pcarbo.github.io/pcarbo/r-macos.html
