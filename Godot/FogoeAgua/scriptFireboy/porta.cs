using Godot;
using System;

public partial class porta : Area2D
{
	private double tempo;
	private bool entrou = false;
	private AnimatedSprite2D animatedSprite2D; 
	public override void _Ready() {
		animatedSprite2D = GetNode<AnimatedSprite2D>("AnimatedSprite2D");
	}

	public override void _Process(double delta)
	{
		if (entrou){
			tempo = tempo + delta;
			animatedSprite2D.Play("abriu");
			if (tempo >= 2) {
				GetTree().ChangeSceneToFile("res://cenasFireboy/vitóriaFireboy.tscn");
			}
			
		}
	}
	
	
	private void entrou_porta(Node2D body)
	{
		if (body is jogadorFireboy){
			tempo=0;
		entrou = true;
		GD.Print("Ganhou!");
		
		}
	}
}


