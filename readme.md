# LCD Kata

This project is an implementation of:
https://codingdojo.org/kata/NumberToLCD/


## VSCode Setup

If you already have a Visual Studio installation set up for C++, follow this:
https://code.visualstudio.com/docs/cpp/config-msvc

Otherwise, follow this guide to install an appropriate compiler:
https://code.visualstudio.com/docs/languages/cpp

Note that MinGW recently had a change that doesn't handle wildcards to specify source files, so cpp files need to be specifically added to the args list in `tasks.json`.

To check if SSH agent is running, run this command in the terminal:
    `ssh-add -l`
    It should output the list of authenticated users.
    If it outputs "Error connecting to agent", you may have to start the agent first.
The SSH agent can be started from the PowerShell terminal like this:
    `Start-Service ssh-agent`
