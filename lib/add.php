<?php

class Students
{
    public $name;
    public $age;
    public $number;
    public $address;

    public function __construct($name, $age, $number, $address)
    {
        $this->name = $name;
        $this->age = $age;
        $this->number = $number;
        $this->address = $address;
    }
}


class Speed extends Students
{
    public $speed;

    public function __construct($name, $age, $number, $address, $speed)
    {
        parent::__construct($name, $age, $number, $address);

        $this->speed = $speed;
    }


    public function pr()
    {
        echo $this->name;
        echo "<br>";

        echo $this->speed;
    }
}


$libya = new Students(
    "Libya",
    20,
    "1234567890",
    "Tripoli"
);


$sd = new Speed(
    "Libya",
    20,
    "1234567890",
    "Tripoli",
    "ibrahim"
);


$sd->pr();

?>