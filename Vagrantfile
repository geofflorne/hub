Vagrant.configure("2") do |config|
  config.vm.box = "ubuntu/xenial64"

  config.vm.provider "virtualbox" do |v|
    v.memory = 4096
  end

  config.vm.provider "vmware_fusion" do |v, override|
    override.vm.box = "geerlingguy/ubuntu1604"
    v.cpus = 2
    v.memory = 4096
  end

  # Sync the project source using rsync
  config.vm.synced_folder ".", "/home/vagrant/hub", type: "rsync", 
    rsync__args: ["--verbose", "--archive", "-z"],
    rsync__exclude: ".git/"

  # Install the required packages
  config.vm.provision "shell", inline: "sudo apt update"
  config.vm.provision "shell", inline: "sudo apt -q -y install build-essential bc libncurses5-dev unzip"
end
