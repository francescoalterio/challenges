import Car from "./Car.js";

export default class Game {
  TREE = "🌲";
  EXPlOSION = "💥";
  TRACK = "_";
  FINISH = "🏁";
  constructor(raceTrackLength) {
    this.raceTrack1 = Array(raceTrackLength).fill(this.TRACK);
    this.raceTrack1[0] = this.FINISH;
    this.raceTrack2 = Array(raceTrackLength).fill(this.TRACK);
    this.raceTrack2[0] = this.FINISH;

    this.car1 = new Car("🚙", raceTrackLength - 1);
    this.car2 = new Car("🚗", raceTrackLength - 1);

    this.raceTrack1[raceTrackLength - 1] = this.car1.carEmoji;
    this.raceTrack2[raceTrackLength - 1] = this.car2.carEmoji;

    let trees1 = 0;
    while (trees1 < 2) {
      const treeLocation =
        Math.floor(Math.random() * (raceTrackLength - 2)) + 1;
      if (this.raceTrack1[treeLocation] !== this.TREE) {
        this.raceTrack1[treeLocation] = this.TREE;
        trees1++;
      }
    }

    let trees2 = 0;
    while (trees2 < 2) {
      const treeLocation =
        Math.floor(Math.random() * (raceTrackLength - 2)) + 1;
      if (this.raceTrack2[treeLocation] !== this.TREE) {
        this.raceTrack2[treeLocation] = this.TREE;
        trees2++;
      }
    }
  }

  init() {
    this.raceInterval = setInterval(() => {
      console.clear();
      const carMove1 = this.car1.move();
      const carMove2 = this.car2.move();

      const newCarPosition1 = this.car1.position - carMove1;
      const newCarPosition2 = this.car2.position - carMove2;

      if (newCarPosition1 <= 0 && newCarPosition2 <= 0) {
        console.clear();
        console.log(this.car1.carEmoji, " <- EMPATE -> ", this.car2.carEmoji);
        clearInterval(this.raceInterval);
      } else if (newCarPosition1 <= 0) {
        console.clear();
        console.log("HA GANADO EL CARRO 1 -> ", this.car1.carEmoji);
        this.raceTrack1[0] = this.car1.carEmoji;
        clearInterval(this.raceInterval);
      } else if (newCarPosition2 <= 0) {
        console.clear();
        console.log("HA GANADO EL CARRO 2 -> ", this.car2.carEmoji);
        this.raceTrack2[0] = this.car2.carEmoji;
        clearInterval(this.raceInterval);
      }

      if (this.raceTrack1[newCarPosition1] === this.TREE) {
        this.raceTrack1[newCarPosition1] = this.EXPlOSION;
        this.raceTrack1[this.car1.position] = this.TRACK;
        this.car1.position = newCarPosition1;
        this.car1.carCollision();
      } else {
        this.raceTrack1[newCarPosition1] = this.car1.carEmoji;
        this.raceTrack1[this.car1.position] = this.TRACK;
        this.car1.position = newCarPosition1;
      }

      if (this.raceTrack2[newCarPosition2] === this.TREE) {
        this.raceTrack2[newCarPosition2] = this.EXPlOSION;
        this.raceTrack2[this.car2.position] = this.TRACK;
        this.car2.position = newCarPosition2;
        this.car2.carCollision();
      } else {
        this.raceTrack2[newCarPosition2] = this.car2.carEmoji;
        this.raceTrack2[this.car2.position] = this.TRACK;
        this.car2.position = newCarPosition2;
      }

      if (carMove1 === 0) {
        this.raceTrack1[newCarPosition1] = this.car1.carEmoji;
      }
      if (carMove2 === 0) {
        this.raceTrack2[newCarPosition2] = this.car2.carEmoji;
      }

      console.log(this.raceTrack1.join(""));
      console.log(this.raceTrack2.join(""));
    }, 1000);
  }
}
