class Player {
    constructor(u, p, s) {
        this.username = u || '';
        this.password = p || '';
        this.scores = [];
        this.highScore = s || 0;
    }

    setUsername(n) {
        this.username = n;
    }

    setPassword(p) {
        this.password = p;
    }

    addScore(s) {
        this.scores.push(s);
        if (s > this.highScore) {
            this.highScore = s;
        }
    }

    getUsername() {
        return this.username;
    }

    getPassword() {
        return this.password;
    }

    getHighScore() {
        return this.highScore;
    }

    printPlayer() {
        console.log(`Username: ${this.username}`);
        console.log(`Password: ${this.password}`);
        console.log(`High Score: ${this.highScore}`);
    }
}

module.exports = Player;
