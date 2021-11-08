This is the place where I put on some short notes on some programming stuff.
============================================================================

### \-- Have my own notes just in case the references or bookmarks are down

#### How to set default Java version in Ubuntu?

To list all the Java versions:

`update-java-alternatives --list`

To set the default Java version:

`update-java-alternatives --set [the name of your Java version]`

Please note that Java 1.x <=> JDK x <=> Java x

##### What if I cannnot find all the Java versions using `update-java-alternatives`?

It seems that `update-java-alternatives` can only find the jdks installed via apt/apt-get/altitude. The following steps will show you how to install a JDK and set your default Java version.

1.  go to [this page](https://www.oracle.com/technetwork/java/javase/downloads/index.html) or [this page](https://www.azul.com/downloads/zulu-community/?&architecture=x86-64-bit&package=jdk) to download a compressed JDK (a tar.gz file)
2.  open a terminal (the default hot-key is Ctrl+Alt+T)
3.  extract the files via typing `tar -xf /path/filename` on terminal
4.  move the folder to a desired place via typing `sudo mv /path/jdk_foldername /desired/path`
5.  change ownership of the folder so that user and group `root` own the file by typing `sudo chown -R root:root /path/jdk_foldername`
6.  type in the following commands to "register" your JDK:  
    `sudo update-alternatives --install /usr/bin/java /path/jdk_foldername/bin/java 200`  
    and  
    `sudo update-alternatives --install /usr/bin/javac /path/jdk_foldername/bin/javac 200`
7.  now you can check your java versions via the following command  
    `update-alternatives --list java`  
    to check your javac versions, replace java with javac in the command
8.  if you want to change your java version, type the following command  
    `sudo update-alternatives --config java`  
    and follow the prompts; to change your javac version, replace java with javac in the command

Reference:

*   [How to set default Java version in Ubuntu – Code Yarns](https://codeyarns.com/2015/12/01/how-to-set-default-java-version-in-ubuntu/)
*   [How To Install Java 7 on Ubuntu 16.04 (Oracle JDK and OpenJDK)](https://www.howtodojo.com/2017/07/install-java-7-ubuntu-16-04/)

  

#### How to set the default zoom level in Firefox without zooming your page each time?

Open a new tab and type in the following:

`about:config`

Click "I accept the risk!" button, then look up `layout.css.devPixelsPerPx`. Double click and set your value.

Note that 1.0 gives you a look and feel as if you set your zoom level to 100%, giving you 96 dpi fonts according to [this link](https://support.mozilla.org/en-US/questions/1147570), 1.5 gives you a look and feel of zoom level 150%. And now if you check your zoom level, it will still be 100%. So changing `layout.css.devPixelsPerPx` is like changing your zoom level's reference frame.

  

#### How to install Adobe Flash Player on Ubuntu?

Open the terminal and type in the following code.

`sudo add-apt-repository "deb http://archive.canonical.com/ $(lsb_release -sc) partner"  
sudo apt update  
sudo apt install adobe-flashplugin browser-plugin-freshplayer-pepperflash  
`

Reference:

*   [Install Adobe Flash Player on Ubuntu 18.04 LTS Desktop | Website for Students](https://websiteforstudents.com/install-adobe-flash-player-on-ubuntu-18-04-lts-beta-desktop/)

  

#### How to install Chinses input method on Ubuntu?

Open the terminal and type in the following code.

`sudo apt update  
sudo apt install ibus ibus-clutter ibus-gtk ibus-gtk3 ibus-qt4  
sudo apt install ibus-pinyin  
sudo apt install ibus-sunpinyin  
`

Do a logout and log back in to let the changes take effect.

Reference:

*   [中文输入法 - Ubuntu中文](https://wiki.ubuntu.com.cn/%E4%B8%AD%E6%96%87%E8%BE%93%E5%85%A5%E6%B3%95)

  

#### How to completely remove a package on Ubuntu?

Open the terminal and type in the following code.

`sudo apt-get --purge autoremove packagename`

Reference:

*   [completely uninstall a package on Ubuntu](https://askubuntu.com/questions/187888/what-is-the-correct-way-to-completely-remove-an-application)

  

#### How to make a plan text become a superscript in MS Word?

Select the text you want and press "Ctrl" + "Shift" + "+".

Sidenote: I came across this problem when I was creating bibliography in MS Word. To create bibliography, click on the "References" tab and then click on "Manage Resources" to add your references. After you have done inputing all your references, click on "Insert Citation" to insert your desired reference at places you want.

Another sidenote: At "References" you can also create table of contents by clickling on "Table of Contents".

  

#### How to activate my Windows / Office when I have a KMS Server?

Follow the following steps

1.  Make sure you downloaded and installed a VL (Volume Licensed) version of Windows / Office.
2.  Open cmd
3.  To activate Windows, please type `slmgr /skms your.kms.server` and `slmgr /ato` to activate.
4.  To activate Office, first type in `cd "Your:\Path\To\Office\OfficeXX"`, and then `cscript ospp.vbs /sethst:your.kms.server` and finally `script ospp.vbs /act` to activate.

Reference:

*   [零散坑](https://03k.org/kms.html)
*   [More info...](https://gist.github.com/CHEF-KOCH/29cac70239eed583ad1c96dcb6de364b)

  

#### How to install and configure PL/SQL Developer?

Follow the following steps

1.  Download [PL/SQL Developer](https://www.allroundautomations.com/products/pl-sql-developer/) and [Oracle Instant Client (Basic Package)](https://www.oracle.com/database/technologies/instant-client/downloads.html)
2.  Extract oracle instant client compressed file to a desired place.
3.  Go to `Control Panel\System and Security\System` and click on "Advanced system settings"
4.  Click on "Advanced" tab, and go to "Environmental Variables..."
5.  On "System Variables", click "New" and set "ORACLE\_HOME" to be "Your:\\Path\\To\\Oracle\\Instant\\Client"
6.  Go to your path to oracle instant client, create a new folder called "tns".
7.  Create another system variable "TNS\_ADMIN" and set it to be "%ORACLE\_HOME\\tns"
8.  Install and activate PL/SQL Developer

Reference:

*   [脚本之家](https://www.jb51.net/softjc/567468.html)

  

#### How install 1013 in VMWare on Windows

NB: They don't like it. And it's against their EULA. Do it at your own risk.

1.  Attain a 1013 iso.
2.  Download and install VMWare Workstation Player 15.10
3.  Download and extract unlocker302
4.  Run win-install as administrator
5.  Create a VM in Workstation Player
6.  Find the VM's VMX file and open it using WordPad
7.  Add `smc.version = "0"` at the end of the file.
8.  Boot up your VM
9.  Select "Disk Utility", select your VMWare disk, click "Erase" and format it to "Mac OS Extended"
10.  Go back to installation menu, select "Install macOS" and let it finish
11.  Download darwin.iso on host and mount it in VM
12.  Follow the prompts to install VMTools
13.  Restart your VM and you're all set.
14.  You can also download and install Beamoff in VM to have better graphic performance (especially if you are using Oracle VBox)

You may see the following message: "This copy of the Install application is damaged, and can't be used to install." To resolve this, do the following:

1.  Disconnect from your internet connection;
2.  In your VM, go to the menu bar on top, select Tools->Terminal;
3.  Go back to your VM, and in the terminal set the date to a date before October 24 (It turns out to be the date on which the security certificate expires). For example, set the date as March 3, 2019 at 00:00 by typing `date 030300002019`
4.  Coneinue with your installation and you should be good.

Reference:

*   [Different but similar](https://techsviewer.com/install-mac-os-x-10-10-yosemite-retail-on-vmware-on-pc/)
*   [A Discussion Thread Regarding The Damaged Installer](https://www.tonymacx86.com/threads/this-copy-of-the-install-macos-mojave-app-application-is-damaged-and-cant-be-used-to-install-macos.285857/)

  

#### How to resize your Linux drive size when you're duo-booting your Linux?

Follow the following steps

1.  Check your available disk size on to make sure your new drive size won't be larger than that.
2.  open a terminal
3.  Make sure your drive has ext4 FS format by typing in`file /Path/To/Your/root.disk` on your terminal
4.  Type in `sudo resize2fs /Path/To/Your/root.disk` to resize your drive.
5.  Reboot

Reference:

*   [怎么扩大Deepin等Linux系统盘root.disk容量大小\_百度经验](https://jingyan.baidu.com/article/c45ad29c761df5051753e213.html)

  

#### A tip of installing Ubuntu on a SSD

Switch the SSD controller mode in BIOS settings from "RAID" to "AHCI".

Reference:

*   [Ubuntu 16.04 installer can't find my SSD on my Dell XPS 15](https://askubuntu.com/questions/924815/ubuntu-16-04-installer-cant-find-my-ssd-on-my-dell-xps-15)

  

#### How to run graphical applications on WSL?

Follow the following steps

1.  Download and install MobaXterm
2.  Open MobaXterm and start a local terminal (or press the X Server button to start the X server)
3.  Open WSL
4.  Run `nano ~/.bashrc`
5.  Add `export DISPLAY=:0` to the end of the file.
6.  Save and close the file and run `source ~/.bashrc`

Reference:

*   [Using WSL and MobaXterm to Create a Linux Dev Environment on Windows — Nick Janetakis](https://nickjanetakis.com/blog/using-wsl-and-mobaxterm-to-create-a-linux-dev-environment-on-windows)

  

#### How to write command line program/script descriptions

Here is a very nice example I found on [docopt.org](http://docopt.org/)

`Naval Fate.  
  
Usage:  
naval_fate ship new ... # "..." <=> argument can be repeated.  
naval_fate ship move [--speed=] # "[] <=> optional parameter  
naval_fate ship shoot  
naval_fate mine (set|remove) [--moored|--drifting] # "() <=> required parameters; | <=> or  
naval_fate -h | --help  
naval_fate --version  
  
Options:  
-h --help Show this screen.  
--version Show version.  
--speed= Speed in knots [default: 10]. # At least two spaces needed.  
--moored Moored (anchored) mine.  
--drifting Drifting mine.`

  

#### Virtual keyboard for Raspberry Pi

`sudo apt-get update  
sudo apt-get install at-spi2-core  
sudo apt-get install florence  
`

  

#### How to set a cronjob on a Linux server if you have shell access?

Use a command called crontab

```# Set the editor for crontab file (vi by default)  
export VISUAL=nano  
  
# Edit the crontab file  
crontab -e  
  
# This is an example of a php cronjob  
* * * * * /inst/bin/php /path/to/your/script.php > /dev/null 2>&1  
  
# The first five "*"s are timing settings which set minutes, hours, days, months, weekday  
# "*" <=> "every"  
# So 0 23 * * * means the cronjob will be executed at 23:00 every day  
# And * 23 * * * means the cronjob will be executed at every minute of the 23rd hour of each day  
# 0 6 1 * * means the cronjob will be executed at 6:00 on the first day of each month  
# 0 4-6 * * 0 means the cron job will be executed at 4:00 ~ 6:00 every Sunday  
  
# "inst/bin/php" tells you what type of script you want to execute  
# Most commands reside in "/usr/bin" e.g. "/usr/bin/php", "/usr/bin/wget", ...  
# Please make sure "where the commands are" by typing:  
which command  
  
# "> /dev/null 2>&1" means discarding output and error message  
# You can use "&> /dev/null" to make it concise  
# You can also use "&> /place/you/want/to/put/your/output" to write out the output  
  
# To list all your cronjobs you can run the following command  
crontab -l  
  
# Check out Crontab Generator for other settings you can do  
```

Reference:

*   [Tania Rascia's blog](https://www.taniarascia.com/setting-up-a-basic-cron-job-in-linux/)
*   [Crontab Generator](https://crontab-generator.org/)

  

#### What if my Outlook gets stuck at "Processing"?

Run Outlook in safe mode to fix itself.

1.  Open an app called "Run"
2.  Type `outlook /safe` and click "OK"
3.  If Outlook successfully opens and logs you in, close it and reopen Outlook to make sure it's fixed

Reference:

*   [Microsoft Office Support](https://support.office.com/en-us/article/Outlook-not-responding-stuck-at-Processing-stopped-working-freezes-or-hangs-5C313D04-64AF-4441-82D2-44E5A43EEE5A)

  

#### How to disable ONLY\_FULL\_GROUP\_BY in MySQL?

There are two solutions:

*   Type `SET GLOBAL sql_mode=(SELECT REPLACE(@@sql_mode,'ONLY_FULL_GROUP_BY',''));` in a MySql console on in PHPMyAdmin
*   Do the following steps in PHPMyAdmin:
    1.  Open PHPMyAdmin and select the database of interest;
    2.  Click "Variables" on the menu bar on the top of the page;
    3.  Scroll down the page until you find a variable named "sql mode";
    4.  Click on "Edit" button on the left, remove "ONLY\_FULL\_GROUP\_BY", and click "Save".

Reference:

*   [Stack Overflow](https://stackoverflow.com/questions/23921117/disable-only-full-group-by)

  

#### How to install plugins for Vim?

There are many ways to install plugins for Vim. I personally prefer using Vim-plug to install and manage my Vim plugins. You can check out my shell script here to install vim-plug and get my Vim configurations.

To manage plugins using Vim-plug, here are some commands you need to know:

*   Type `:so %` at your opened vimrc file to "apply" the changes you have made.
*   Type `:PlugInstall` at your opened vimrc file to begin the installations for the plugins you add.
*   Type `:PlugStatus` at your opened vimrc file to check the statu of your plugins.
*   Type `:PlugUpdate` at your opened vimrc file to update your plugins.
*   If you want to remove a plugin, remove or comment out the line at the "Vim-plug section" and type `:PlugClean`

Reference:

*   [A blog that has more detailed information on installing plugins in Vim](https://linuxhint.com/vim_install_plugins/)

  

#### What to do when my Adobe Acrobat Pro keeps closing itself?

Do the following. It basically resets the user configurations (including license) of the software.

1.  Go to `C:\Program Files (x86)\Common File\Adobe\` and rename folder "SLCache" to "OldSLCache"
2.  Go to `C:\Program Data\Adobe\` and rename folder "SLStore" to "OldSLStore"
3.  Run the Adobe Acrobat Pro as Admin and you are all set. You may need to re-enter your license information.

Reference:

*   [Solution provided by an Adobe employee](https://community.adobe.com/t5/acrobat/adobe-acrobat-xi-pro-keeps-closing-second-after-launching-or-opening-a-pdf/td-p/6499118?page=1)

  

#### How to export/backup databases from SQL Server on Amazon RDS?

Depending on what output format you want. There are two solutions:

<ul>
    <li>
        Run the following code in SQL Server Management Studio (SSMS) after you have connected to your AWS server. The code will output a bak file to your AWS bucket which you need to create before creating an RDS instance:
        <div class="w3-panel w3-grey w3-round w3-padding">
            <code>
                EXEC msdb.dbo.rds_backup_database<br>
                    @source_db_name = 'your_database_name',<br>
                    @S3_arn_to_backup_to = 'arn:asw:s3:::your-bucket-name/folder/db.bak',<br>
                    [@kms_master_key_arn='arn:aws:kms:region:account-id:key/key-id'],<br>
                    [@overwrite_s3_backup_file=0|1],<br>
                    [@type='DIFFERENTIAL|FULL'],<br>
                    [@number_of_files=n];
            </code>
        </div>
    </li>
    <li>
        Do the following to attain an SQL script that recreates your database:
        <ol>
            <li>Open SSMS and connect to your database server</li>
            <li>Right click on the database you want to backup and go to Tasks->Generate Scripts</li>
            <li>Follow the prompts and you are all set.</li>
        </ol>
    </li>
</ul>

Reference:

*   [Stack Overflow](https://stackoverflow.com/questions/27034041/how-to-export-backup-db-from-sql-server-on-amazon-rds)
*   [AWS document about the database backup and restore](https://docs.aws.amazon.com/AmazonRDS/latest/UserGuide/SQLServer.Procedural.Importing.html)
*   [How to generate a SQL script that recreate the database in SSMS](https://ourcodeworld.com/articles/read/846/how-to-export-a-ms-sql-server-database-to-a-sql-script-database-to-sql-file-with-microsoft-sql-server-management-studio-17)