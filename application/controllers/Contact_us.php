<?php

/**
 * Description of Problems
 *
 * @author anuj
 */
defined('BASEPATH') OR exit('No direct script access allowed');

class Contact_us extends CI_Controller {

    var $username;
    var $assignment;
    var $user_level;
    var $error_messages;
    var $success_messages;
    var $edit_assignment;
    var $edit;

    // ------------------------------------------------------------------------


    public function __construct() {
        parent::__construct();
        $this->load->driver('session');
        if (!$this->session->userdata('logged_in')) // if not logged in
            redirect('login');

        $this->username = $this->session->userdata('username');
        $this->assignment = $this->assignment_model->assignment_info($this->user_model->selected_assignment($this->username));
        $this->user_level = $this->user_model->get_user_level($this->username);
        $this->problems = $this->assignment_model->all_problems($this->assignment['id']);

        $this->error_messages = array();
        $this->success_messages = array();
        $this->edit_assignment = array();
        $this->edit = FALSE;
    }

    public function index() {
 
        $data = array(
            'username' => $this->username,
            'user_level' => $this->user_level,
            'title' => 'Contact Us',
            'style' => 'main.css',
            'all_assignments' => $this->assignment_model->all_assignments(),
            'assignment' => $this->assignment,
            'title' => 'Contact Us'
        );
        $this->load->view('templates/header', $data);
        $this->load->view('pages/contact', $data);
        $this->load->view('templates/footer');
    }
}
