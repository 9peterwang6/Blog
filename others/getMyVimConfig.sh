# This is a shell script that I write
# to retrieve my personal VIM configurations
# when I switch to a new workstation.


# First I need to download vim-plug.
# The following code is from
# https://linuxhint.com/vim_install_plugins/
curl -fLo ~/.vim/autoload/plug.vim --create-dirs \
	https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim


# Then I need to download my vimrc file
curl -fLo ~/vimrc \
	https://raw.githubusercontent.com/9peterwang6/9peterwang6.github.io/master/others/vimrc


# The next thing is to rename my vimrc file
# to ".vimrc".
mv ~/vimrc ~/.vimrc


# The final steps will be the following:
# vim ~/.vimrc
# :PlugInstall
# And then you are all set!
