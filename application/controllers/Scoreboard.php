<?php
/**
 * Sharif Judge online judge
 * @file Scoreboard.php
 * @author Mohammad Javad Naderi <mjnaderi@gmail.com>
 */
defined('BASEPATH') OR exit('No direct script access allowed');

class Scoreboard extends CI_Controller
{

	var $username;
	var $assignment;
	var $user_level;


	// ------------------------------------------------------------------------


	public function __construct()
	{
		parent::__construct();
		if ($this->input->is_cli_request())
			return;
		$this->load->driver('session');
		if ( ! $this->session->userdata('logged_in')) // if not logged in
			redirect('login');
		$this->username = $this->session->userdata('username');
		$this->assignment = $this->assignment_model->assignment_info($this->user_model->selected_assignment($this->username));
                $this->problems = $this->assignment_model->all_problems($this->assignment['id']);
		$this->user_level = $this->user_model->get_user_level($this->username);
	}


	// ------------------------------------------------------------------------


	public function score()
	{

		$this->load->model('scoreboard_model');

		$data = array(
			'username' => $this->username,
			'user_level' => $this->user_level,
			'all_assignments' => $this->assignment_model->all_assignments(),
			'assignment' => $this->assignment,
			'title' => 'Scoreboard',
			'style' => 'main.css',
			'scoreboard' => $this->scoreboard_model->get_scoreboard($this->assignment['id'])
		);

		$this->load->view('templates/header', $data);
		$this->load->view('pages/scoreboard_old', $data);
		$this->load->view('templates/footer');
	}


	// ------------------------------------------------------------------------


        public function index() {

		$this->load->model('scoreboard_model');
                //$scoreboard_1 = $this->generate_each_round($this->assignment['id']);
		//$scoreboard_2 = $this->generate_each_round($this->assignment['id']-1);
                $scoreboard = $this->scoreboard_model->get_scoreboard($this->assignment['id']);

		$data = array(
			'username' => $this->username,
			'user_level' => $this->user_level,
			'all_assignments' => $this->assignment_model->all_assignments(),
			'assignment' => $this->assignment,
			'title' => 'Scoreboard',
			'style' => 'main.css',
                        'notification_count' => $notif_count ? $notif_count : 0,
                        'problems' => $this->problems,
			//'scoreboard_1' => $scoreboard_1,
			//'scoreboard_2' => $scoreboard_2,
                        'scoreboard' => $scoreboard,
			'total_scores' => $this->generate_total($scoreboard_1, $scoreboard_2)
		);

		$this->load->view('templates/header', $data);
		$this->load->view('pages/scoreboard_old', $data);
		$this->load->view('templates/footer');
            
        }


	// ------------------------------------------------------------------------


        private function generate_total($score1, $score2) {

            $total_scores = array();

            foreach ($score1 as $user => $data) {
                $total_scores[$user]['score'] = $data['total_score'] + $score2[$user]['total_score'];
                $total_scores[$user]['total_time'] = $data['total_time'] + $score2[$user]['total_time'];
            }
            
            foreach ($score2 as $user => $data) {
                if(isset($score1[$user])) continue;
                $total_scores[$user]['score'] = $data['total_score'];
                $total_scores[$user]['total_time'] = $data['total_time'];
            }

            function cmp($a, $b) {
                if($a['score'] > $b['score']) return -1;
                if ($a['score'] < $b['score']) return 1;
                if($a['total_time'] > $b['total_time']) return 1;
                if($a['total_time'] < $b['total_time']) return -1;
                return 0;
            }
            
            uasort($total_scores, 'cmp');
            return $total_scores;
        }


	// ------------------------------------------------------------------------


        /*
         * Function to generate scoreboard for a given assignment_id
         */
        private function generate_each_round($assignment_id) {
      		$submissions = $this->db->get_where('final_submissions', array('assignment'=>$assignment_id))->result_array();
                $assignment = $this->assignment_model->assignment_info($assignment_id);
		$finish = strtotime($assignment['finish_time']);
		$submit_penalty = $this->settings_model->get_setting('submit_penalty');
		$scoreboard = array();
		foreach ($submissions as $submission){

			$pi = $this->assignment_model->problem_info($assignment_id, $submission['problem']);

			$pre_score = ceil($submission['pre_score']*$pi['score']/10000);
			if ($submission['coefficient'] === 'error')
				$final_score = 0;
			else
				$final_score = ceil($pre_score*$submission['coefficient']/100);
			$delay = strtotime($submission['time'])-strtotime($assignment['start_time']);
			$scoreboard[$submission['username']]['problems'][$submission['problem']]['score'] = $final_score;
			$scoreboard[$submission['username']]['problems'][$submission['problem']]['time'] = $delay;

			if ( ! isset($total_score[$submission['username']]))
				$total_score[$submission['username']] = 0;
			if ( ! isset($penalty[$submission['username']]))
				$penalty[$submission['username']] = 0;

			$scoreboard[$submission['username']]['total_score'] += $final_score;
			$scoreboard[$submission['username']]['total_time'] += $delay+$submission['submit_count']*$submit_penalty;
		}
                return $scoreboard;
        }

}
