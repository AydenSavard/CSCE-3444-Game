class Players {
  constructor(c) {
    this.playercount = c || 0;
    this.playerlist = [];
  }

  getCount() {
    return this.playercount;
  }

  addPlayer(u, p, s) {
    this.playerlist.push(new Player(u, p, s));
    this.playercount++;
  }

  deletePlayer(user) {
    for (let i = 0; i < this.playerlist.length; i++) {
      if (this.playerlist[i].getUsername() === user) {
        this.playerlist.splice(i, 1);
        this.playercount--;
        break;
      }
    }
  }

  editPlayer(user, newu, newp) {
    const player = this.searchPlayer(user);
    if (player) {
      player.setUsername(newu);
      player.setPassword(newp);
    }
  }

  searchPlayer(user) {
    for (let i = 0; i < this.playerlist.length; i++) {
      if (this.playerlist[i].getUsername() === user) {
        return this.playerlist[i];
      }
    }
    return null;
  }

  printPlayerlist() {
    console.log("Player Count: " + this.playercount);
    console.log("Player List:");
    for (let i = 0; i < this.playerlist.length; i++) {
      console.log("Player " + (i + 1) + ": " + this.playerlist[i].getUsername());
    }
  }

  printPlayerData(user) {
    const player = this.searchPlayer(user);
    if (player) {
      player.printPlayer();
    }
  }

  storePlayer() {
    // Implementation dependent on storage mechanism
  }

  loadPlayer() {
    // Implementation dependent on storage mechanism
  }

  cleanup() {
    // Cleanup code goes here
  }
}
