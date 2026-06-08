# History of Use

We started using this code around 2014, initially forking it as in internal repo.
(At the time, we could not directly pull open source repos into our build systems; repos needed to be internal.)
It became heavily used and relied upon.
We seriously love this handling of scientific units of measure for C++.
In 2015, a project using it was brought to open-source as the [FIM MOPS Aircraft and Control Model](htps://github.com/mitre/fmacm) and the C++ Units of Measure library was included as an embedded library.
That code base is licensed using Apache 2.0.

Over time, it became clear that this C++ Units of Measure code base really needed to be independently managed, having its own git repo.
And for our software, this needed to be in the open-source arena on GitHub.
There had been no apparent work in the open-source arena to bring the original repo out of retirement.
Since the code was already quietly part of the [FIM MOPS Aircraft and Control Model](htps://github.com/mitre/fmacm), we chose to break that up in order to create this repo.
