using Godot;
using System;

public partial class ButtonJogarFireboy : Button
{
	
	private void jogar_fireboy()
	{
		GetTree().ChangeSceneToFile("res://cenasFireboy/mapa_2.tscn");
	}
}
