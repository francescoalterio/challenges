export default class Car {
  collision = false;
  constructor(carEmoji, position) {
    this.carEmoji = carEmoji;
    this.position = position;
  }

  move() {
    if (this.collision) {
      this.collision = false;
      return 0;
    } else {
      return Math.floor(Math.random() * 3 + 1);
    }
  }

  carCollision() {
    this.collision = true;
  }
}
